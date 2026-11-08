#!/usr/bin/env bash
#
# ─────────────────────────────────────────────────────────────────────────────
#  run.sh — compile & run a C++ file from the terminal, professionally.
#
#  Part of the data-structure learning repository.
#  Mirrors the VS Code task in .vscode/tasks.json (same flags, same output
#  location), so both workflows behave identically.
#
#  Usage:
#      ./run.sh [options] <source.cpp> [program-args...]
#
#  Options (must come BEFORE the source file):
#      -d, --debug          Debug build: -g -O0 + warnings         (default)
#      -r, --release        Release build: -O2 -DNDEBUG + warnings
#      -s, --sanitize       Add AddressSanitizer + UBSan (debug aid)
#      -c, --compile-only   Build but do not run
#      -f, --force          Recompile even if the binary is up to date
#      -q, --quiet          Minimal output
#          --clean          Remove the compiled binary and exit
#      -h, --help           Show this help
#      -V, --version        Show version
#
#  Examples:
#      ./run.sh 01-arrays/problems/two_sum.cpp
#      ./run.sh -r 01-arrays/problems/two_sum.cpp
#      ./run.sh -s 07-recursion-and-backtracking/problems/n_queens.cpp
#      ./run.sh 13-searching/problems/binary_search.cpp 42      # program args
#      ./run.sh problems/main.cpp < input.txt                   # stdin passes through
#      ./run.sh --clean 01-arrays/problems/two_sum.cpp
#
#  Behaviour:
#      • Binary goes next to the source (<name>.exe on Windows) — git-ignored.
#      • Recompiles only when the source is newer than the binary.
#      • Propagates the program's exit code.
#
#  Requires: g++ (MSYS2/MinGW, Linux, or macOS). Override with $CXX.
# ─────────────────────────────────────────────────────────────────────────────

set -euo pipefail

VERSION="1.0.0"

# ── Colors (auto-disabled when piping or when NO_COLOR is set) ───────────────
setup_colors() {
    if [[ -t 1 && -z "${NO_COLOR:-}" ]]; then
        C_RESET=$'\e[0m'; C_BOLD=$'\e[1m'; C_DIM=$'\e[2m'
        C_RED=$'\e[31m'; C_GREEN=$'\e[32m'; C_YELLOW=$'\e[33m'; C_CYAN=$'\e[36m'
    else
        C_RESET=""; C_BOLD=""; C_DIM=""
        C_RED=""; C_GREEN=""; C_YELLOW=""; C_CYAN=""
    fi
}

info() { (( QUIET )) || printf '%s\n' "${C_CYAN}▸${C_RESET} $*"; }
ok()   { (( QUIET )) || printf '%s\n' "${C_GREEN}✓${C_RESET} $*"; }
warn() { printf '%s\n' "${C_YELLOW}⚠${C_RESET} $*" >&2; }
err()  { printf '%s\n' "${C_RED}✗${C_RESET} $*" >&2; }
die()  { err "$@"; exit 1; }

# ── Millisecond clock (bash ≥5 EPOCHREALTIME, with date fallback) ───────────
now_ms() {
    local t
    if [[ -n "${EPOCHREALTIME:-}" ]]; then
        t="${EPOCHREALTIME/./}"
        printf '%s' "${t:0:13}"
    else
        date +%s%3N
    fi
}

fmt_ms() {  # 1234 -> "1.23 s" · 456 -> "456 ms"
    local ms="$1"
    if (( ms >= 1000 )); then
        printf '%d.%02d s' $(( ms / 1000 )) $(( (ms % 1000) / 10 ))
    else
        printf '%d ms' "$ms"
    fi
}

usage() {
    cat <<EOF
${C_BOLD}run.sh${C_RESET} — compile & run a C++ file from the terminal (v${VERSION})

${C_BOLD}Usage:${C_RESET}
    ./run.sh [options] <source.cpp> [program-args...]

${C_BOLD}Options${C_RESET} (before the source file):
    -d, --debug          Debug build: -std=c++17 -g -O0 -Wall -Wextra  (default)
    -r, --release        Release build: -O2 -DNDEBUG -Wall -Wextra
    -s, --sanitize       AddressSanitizer + UBSan (MSYS2 needs libasan pkgs; falls back)
    -c, --compile-only   Compile without running
    -f, --force          Recompile even if the binary is up to date
    -q, --quiet          Minimal output
        --clean          Delete the compiled binary
    -h, --help           Show this help
    -V, --version        Show version

${C_BOLD}Examples:${C_RESET}
    ./run.sh 01-arrays/problems/two_sum.cpp
    ./run.sh -r 13-searching/problems/binary_search.cpp
    ./run.sh -s 03-linked-lists/problems/reverse_linked_list.cpp
    ./run.sh 11-graphs/problems/bfs.cpp 5        # args after the file → the program
    ./run.sh main.cpp < input.txt                # stdin passes through

The binary is placed next to the source and only rebuilt when the source
changes. Works on MSYS2/Git Bash (Windows), Linux, and macOS.
EOF
}

# ── Locate a compiler: $CXX → PATH → common MSYS2/MinGW locations ───────────
pick_compiler() {
    local cand
    if [[ -n "${CXX:-}" ]] && command -v "$CXX" >/dev/null 2>&1; then
        command -v "$CXX"; return 0
    fi
    if command -v g++ >/dev/null 2>&1; then
        command -v g++; return 0
    fi
    for cand in \
        /c/msys64/ucrt64/bin/g++.exe \
        /c/msys64/mingw64/bin/g++.exe \
        /mingw64/bin/g++.exe \
        /c/mingw64/bin/g++.exe
    do
        if [[ -f "$cand" ]]; then printf '%s' "$cand"; return 0; fi
    done
    return 1
}

# ═════════════════════════════════════════════════════════════════════════════
#  Main
# ═════════════════════════════════════════════════════════════════════════════
setup_colors

MODE="debug"; SANITIZE=0; COMPILE_ONLY=0; FORCE=0; QUIET=0; CLEAN=0; SRC=""

while [[ $# -gt 0 ]]; do
    case "$1" in
        -d|--debug)         MODE="debug" ;;
        -r|--release)       MODE="release" ;;
        -s|--sanitize)      SANITIZE=1 ;;
        -c|--compile-only)  COMPILE_ONLY=1 ;;
        -f|--force)         FORCE=1 ;;
        -q|--quiet)         QUIET=1 ;;
        --clean)            CLEAN=1 ;;
        -h|--help)          usage; exit 0 ;;
        -V|--version)       printf 'run.sh %s\n' "$VERSION"; exit 0 ;;
        -*)                 usage >&2; die "unknown option: $1" ;;
        *)                  SRC="$1"; shift; break ;;
    esac
    shift
done
PROG_ARGS=("$@")

if [[ -z "$SRC" ]]; then
    usage >&2
    die "no source file given"
fi

case "$SRC" in
    *.cpp|*.cc|*.cxx|*.c++|*.cp) ;;
    *) die "not a C++ source file: $SRC" ;;
esac

[[ -f "$SRC" ]] || die "file not found: $SRC"

# Absolute path of the source (works with spaces in the path)
SRC_ABS=$(cd "$(dirname "$SRC")" && pwd)/$(basename "$SRC")

# Windows binaries need the .exe suffix
OS="$(uname -s)"
case "$OS" in
    MINGW*|MSYS*|CYGWIN*) EXE=".exe" ;;
    *)                     EXE="" ;;
esac
BIN="${SRC_ABS%.*}${EXE}"

# ── --clean: remove the binary and exit ─────────────────────────────────────
if (( CLEAN )); then
    if [[ -f "$BIN" ]]; then
        rm -- "$BIN"
        ok "removed ${C_DIM}$BIN${C_RESET}"
    else
        warn "nothing to clean (no binary at ${C_DIM}$BIN${C_RESET})"
    fi
    exit 0
fi

CXX_BIN="$(pick_compiler)" || die "g++ not found — install MSYS2 (ucrt64) or set CXX=/path/to/g++"

# ── Decide whether to rebuild ────────────────────────────────────────────────
needs_build() {
    if (( FORCE )); then return 0; fi
    if [[ ! -f "$BIN" ]]; then return 0; fi
    if [[ "$SRC_ABS" -nt "$BIN" ]]; then return 0; fi
    return 1
}

if needs_build; then
    FLAGS=(-std=c++17 -Wall -Wextra)
    case "$MODE" in
        release) FLAGS+=(-O2 -DNDEBUG) ;;
        debug)   FLAGS+=(-g -O0) ;;
    esac
    info "compiling ${C_BOLD}$(basename "$SRC")${C_RESET} ${C_DIM}[$MODE]${C_RESET}"
    t0=$(now_ms)
    BUILD_OK=0
    if (( SANITIZE )); then
        # LeakSanitizer is unavailable on Windows — silence the warning.
        case "$OS" in
            MINGW*|MSYS*|CYGWIN*) export ASAN_OPTIONS="${ASAN_OPTIONS:-detect_leaks=0}" ;;
        esac
        if "$CXX_BIN" "${FLAGS[@]}" -fsanitize=address,undefined -fno-omit-frame-pointer "$SRC_ABS" -o "$BIN"; then
            BUILD_OK=1
        else
            warn "sanitizers are not installed in this toolchain — building without them"
            warn "enable them (MSYS2/ucrt64):  pacman -S mingw-w64-ucrt-x86_64-libasan mingw-w64-ucrt-x86_64-libubsan"
        fi
    fi
    if (( BUILD_OK == 0 )); then
        "$CXX_BIN" "${FLAGS[@]}" "$SRC_ABS" -o "$BIN" || die "compilation failed"
    fi
    t1=$(now_ms)
    ok "built in $(fmt_ms $((t1 - t0))) → ${C_DIM}$BIN${C_RESET}"
else
    (( QUIET )) || info "binary is up to date — skipping compile ${C_DIM}(--force to rebuild)${C_RESET}"
fi

if (( COMPILE_ONLY )); then
    ok "compile-only mode — not running"
    exit 0
fi

info "running ${C_BOLD}$(basename "$BIN")${C_RESET}${PROG_ARGS[@]:+ ${C_DIM}${PROG_ARGS[*]}${C_RESET}}"
t0=$(now_ms)
set +e
"$BIN" ${PROG_ARGS[@]+"${PROG_ARGS[@]}"}
STATUS=$?
set -e
t1=$(now_ms)

if (( STATUS == 0 )); then
    ok "finished in $(fmt_ms $((t1 - t0)))"
else
    err "program exited with code ${STATUS} ${C_DIM}(ran $(fmt_ms $((t1 - t0))))${C_RESET}"
fi
exit "$STATUS"
