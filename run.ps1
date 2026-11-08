# ============================================================================
#  run.ps1 - compile & run a C++ file from PowerShell, professionally.
#
#  PowerShell twin of run.sh (same flags, same behaviour, same output style).
#  Part of the data-structure learning repository.
#  Mirrors the VS Code task in .vscode/tasks.json.
#
#  Usage:
#      .\run.ps1 [options] <source.cpp> [program-args...]
#
#  Options:
#      -Release       Release build: -O2 -DNDEBUG -Wall -Wextra
#                     (default is a debug build: -g -O0 -Wall -Wextra)
#      -Sanitize      Add AddressSanitizer + UBSan (falls back gracefully)
#      -CompileOnly   Build but do not run
#      -Force         Recompile even if the binary is up to date
#      -Quiet         Minimal output
#      -Clean         Remove the compiled binary and exit
#      -Help          Show this help
#      -Version       Show version
#
#  Examples:
#      .\run.ps1 01-arrays\examples\arrays_guide.cpp
#      .\run.ps1 -Release 01-arrays\problems\two_sum.cpp
#      .\run.ps1 13-searching\problems\binary_search.cpp 42
#      .\run.ps1 -Clean 01-arrays\examples\arrays_guide.cpp
#
#  If PowerShell blocks this script ("running scripts is disabled"), allow
#  local scripts once for your user:
#      Set-ExecutionPolicy -Scope CurrentUser RemoteSigned
#
#  Works on Windows PowerShell 5.1 and PowerShell 7+ (ASCII output only).
# ============================================================================

[CmdletBinding()]
param(
    [switch]$Release,
    [switch]$Sanitize,
    [switch]$CompileOnly,
    [switch]$Force,
    [switch]$Quiet,
    [switch]$Clean,
    [switch]$Help,
    [switch]$Version,
    [Parameter(Position = 0)]
    [string]$Source,
    [Parameter(ValueFromRemainingArguments = $true)]
    [string[]]$ProgramArgs
)

$ErrorActionPreference = 'Stop'
$ScriptVersion = '1.0.0'

# ----------------------------------------------------------------------------
#  Output helpers - ASCII markers, safe in every codepage and PS version.
# ----------------------------------------------------------------------------
function Write-Info {
    param([string]$Message)
    if (-not $Quiet) { Write-Host '>>' $Message -ForegroundColor Cyan }
}
function Write-Ok {
    param([string]$Message)
    if (-not $Quiet) { Write-Host 'OK' $Message -ForegroundColor Green }
}
function Write-Warn {
    param([string]$Message)
    Write-Host '!!' $Message -ForegroundColor Yellow
}
function Write-Err {
    param([string]$Message)
    Write-Host 'XX' $Message -ForegroundColor Red
}

function Format-Ms {
    # 1234 -> "1.23 s" ; 456 -> "456 ms"
    param([double]$Ms)
    if ($Ms -ge 1000) { return ('{0:N2} s' -f ($Ms / 1000.0)) }
    return ('{0:N0} ms' -f $Ms)
}

function Show-Usage {
    Write-Host @'
run.ps1 - compile & run a C++ file from the terminal (v1.0.0)

Usage:
    .\run.ps1 [options] <source.cpp> [program-args...]

Options (before the source file):
    -Release        Release build: -O2 -DNDEBUG -Wall -Wextra
    -Sanitize       AddressSanitizer + UBSan (MSYS2 needs libasan pkgs; falls back)
    -CompileOnly    Compile without running
    -Force          Recompile even if the binary is up to date
    -Quiet          Minimal output
    -Clean          Delete the compiled binary
    -Help           Show this help
    -Version        Show version

Examples:
    .\run.ps1 01-arrays\examples\arrays_guide.cpp
    .\run.ps1 -Release 13-searching\problems\binary_search.cpp
    .\run.ps1 -s 03-linked-lists\problems\reverse_linked_list.cpp
    .\run.ps1 11-graphs\problems\bfs.cpp 5        # args after the file -> the program
    .\run.ps1 main.cpp                           # forward slashes work too

The binary is placed next to the source and only rebuilt when the source
changes. Works on Windows PowerShell 5.1 and PowerShell 7+.
'@
}

# ----------------------------------------------------------------------------
#  Compiler discovery: $env:CXX -> g++ on PATH -> common MSYS2/MinGW spots.
# ----------------------------------------------------------------------------
function Get-Compiler {
    if ($env:CXX) {
        $cmd = Get-Command $env:CXX -ErrorAction SilentlyContinue
        if ($cmd) { return $cmd.Source }
    }
    $gpp = Get-Command g++ -ErrorAction SilentlyContinue
    if ($gpp) { return $gpp.Source }
    foreach ($path in @(
            'C:\msys64\ucrt64\bin\g++.exe',
            'C:\msys64\mingw64\bin\g++.exe',
            'C:\mingw64\bin\g++.exe')) {
        if (Test-Path -LiteralPath $path) { return $path }
    }
    return $null
}

# ============================================================================
#  Main
# ============================================================================

if ($Version) {
    Write-Host "run.ps1 $ScriptVersion"
    exit 0
}
if ($Help) {
    Show-Usage
    exit 0
}
if (-not $Source) {
    Show-Usage
    Write-Err 'no source file given'
    exit 2
}
if ($Source -notmatch '\.(cpp|cc|cxx|c\+\+|cp)$') {
    Write-Err "not a C++ source file: $Source"
    exit 2
}

# Resolve to an absolute path (handles relative paths and spaces).
try   { $Src = (Get-Item -LiteralPath $Source).FullName }
catch { Write-Err "file not found: $Source"; exit 2 }

$Dir  = Split-Path -Parent $Src
$Base = [System.IO.Path]::GetFileNameWithoutExtension($Src)
$Bin  = Join-Path $Dir ($Base + '.exe')

# ---- -Clean: remove the binary and exit ------------------------------------
if ($Clean) {
    if (Test-Path -LiteralPath $Bin) {
        Remove-Item -LiteralPath $Bin
        Write-Ok "removed $Bin"
    }
    else {
        Write-Warn "nothing to clean (no binary at $Bin)"
    }
    exit 0
}

$Cxx = Get-Compiler
if (-not $Cxx) {
    Write-Err 'g++ not found - install MSYS2 (ucrt64) or set $env:CXX'
    exit 1
}

# ---- Decide whether to rebuild ----------------------------------------------
$NeedsBuild = $true
if (-not $Force -and (Test-Path -LiteralPath $Bin)) {
    $srcTime = (Get-Item -LiteralPath $Src).LastWriteTimeUtc
    $binTime = (Get-Item -LiteralPath $Bin).LastWriteTimeUtc
    if ($srcTime -le $binTime) { $NeedsBuild = $false }
}

if ($NeedsBuild) {

    $Flags    = @('-std=c++17', '-Wall', '-Wextra')
    $ModeName = 'debug'
    if ($Release) { $Flags += @('-O2', '-DNDEBUG'); $ModeName = 'release' }
    else          { $Flags += @('-g', '-O0') }

    Write-Info ("compiling {0} [{1}]" -f (Split-Path -Leaf $Src), $ModeName)
    $sw      = [System.Diagnostics.Stopwatch]::StartNew()
    $BuildOk = $false

    if ($Sanitize) {
        # LeakSanitizer is unavailable on Windows - silence the warning later.
        if (-not $env:ASAN_OPTIONS) { $env:ASAN_OPTIONS = 'detect_leaks=0' }

        & $Cxx @Flags '-fsanitize=address,undefined' '-fno-omit-frame-pointer' -o $Bin $Src
        if ($LASTEXITCODE -eq 0) {
            $BuildOk = $true
        }
        else {
            Write-Warn 'sanitizers are not installed in this toolchain - building without them'
            Write-Warn 'enable them (MSYS2/ucrt64): pacman -S mingw-w64-ucrt-x86_64-libasan mingw-w64-ucrt-x86_64-libubsan'
        }
    }
    if (-not $BuildOk) {
        & $Cxx @Flags -o $Bin $Src
        if ($LASTEXITCODE -ne 0) {
            Write-Err 'compilation failed'
            exit 1
        }
    }
    $sw.Stop()
    Write-Ok ("built in {0} -> {1}" -f (Format-Ms $sw.Elapsed.TotalMilliseconds), $Bin)
}
else {
    Write-Info 'binary is up to date - skipping compile (-Force to rebuild)'
}

if ($CompileOnly) {
    Write-Ok 'compile-only mode - not running'
    exit 0
}

# ---- Run the program, forward program args, time it, propagate exit code ---
if ($ProgramArgs) {
    Write-Info ("running {0} {1}" -f (Split-Path -Leaf $Bin), ($ProgramArgs -join ' '))
}
else {
    Write-Info ("running {0}" -f (Split-Path -Leaf $Bin))
}

$sw2 = [System.Diagnostics.Stopwatch]::StartNew()
if ($ProgramArgs) { & $Bin @ProgramArgs }
else              { & $Bin }
$Status = $LASTEXITCODE
$sw2.Stop()

if ($Status -eq 0) {
    Write-Ok ("finished in {0}" -f (Format-Ms $sw2.Elapsed.TotalMilliseconds))
}
else {
    Write-Err ("program exited with code {0} (ran {1})" -f $Status, (Format-Ms $sw2.Elapsed.TotalMilliseconds))
}
exit $Status
