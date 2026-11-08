// ═══════════════════════════════════════════════════════════════════════════
//  01 · ARRAYS — Comprehensive C++ Learning Examples
//  ─────────────────────────────────────────────────────────────────────────
//  Repository : data-structure/01-arrays
//  Run        : ./run.sh 01-arrays/examples/arrays_guide.cpp
//  Compile    : g++ -std=c++17 -Wall -Wextra -g
//
//  One compilable file that walks through everything an array is and does:
//    §1  What an array is — memory layout, O(1) access, decay pitfall
//    §2  Static (std::array) vs dynamic (std::vector) containers
//    §3  Core operations — search, insert, delete, reverse (+ complexities)
//    §4  2D arrays — matrices, row-major memory, grid-as-graph
//    §5  The five essential array patterns
//    §6  Real-world use case — exam score analytics
// ═══════════════════════════════════════════════════════════════════════════

#include <algorithm>   // sort, max_element, stable_sort
#include <array>       // std::array
#include <iomanip>     // setprecision
#include <iostream>
#include <numeric>     // accumulate, iota
#include <stdexcept>   // out_of_range
#include <string>
#include <utility>     // swap
#include <vector>

// `using namespace std;` is fine for a learning file — in real projects,
// prefer explicit `std::` prefixes to avoid name collisions.
using namespace std;

// Small helper: print a section banner so the output is easy to follow.
static void banner(const string& title) {
    cout << "\n════════════════ " << title << " ════════════════\n";
}

// Small helper: print a vector as [ a b c ].
static void print(const vector<int>& a) {
    cout << "[ ";
    for (int x : a) cout << x << ' ';
    cout << "]\n";
}

// ⚠️ PITFALL 2 companion — arrays DECAY to pointers when passed.
// Writing `int arr[]` as a parameter is really `int* arr`: the length is
// lost, which is why C-style functions always ask for the size separately.
static void decayDemo(int* arr) {
    cout << "sizeof(arr) inside a function = " << sizeof(arr)
         << " bytes (just a pointer — size info is lost!)\n";
}

// ═══════════════════════════════════════════════════════════════════════════
//  §1 · WHAT IS AN ARRAY?
//  An array stores N elements of the same type in ONE CONTIGUOUS memory
//  block. That single fact explains everything: why access is O(1), why
//  insertion in the middle is O(n), and why arrays are cache-friendly.
// ═══════════════════════════════════════════════════════════════════════════
static void section1_fundamentals() {
    banner("§1 · WHAT IS AN ARRAY?");

    // A raw C array: 5 ints packed side by side in memory.
    int scores[5] = {88, 92, 75, 61, 95};

    // ACCESS — O(1). No scanning: the compiler computes the exact address:
    //     address of scores[i] = base + i * sizeof(int)
    cout << "scores[0] = " << scores[0] << "   (first element)\n";
    cout << "scores[4] = " << scores[4] << "   (last element)\n";

    // Contiguity is real — watch the addresses climb by 4 bytes each step:
    for (int i = 0; i < 3; ++i)
        cout << "  &scores[" << i << "] = " << &scores[i] << '\n';

    // TRAVERSAL — O(n): touch every element exactly once.
    cout << "all elements: ";
    for (int i = 0; i < 5; ++i) cout << scores[i] << ' ';
    cout << '\n';

    // RANGE-BASED for (C++11) — cleaner when you don't need the index.
    int total = 0;
    for (int s : scores) total += s;
    cout << "sum = " << total << '\n';

    // ⚠️ PITFALL 1 — no bounds checking. scores[5] compiles fine but is
    //    UNDEFINED BEHAVIOR (reading whatever sits past the array).
    //    Prefer std::vector::at() or std::array::at(), which throw instead.

    // ⚠️ PITFALL 2 — sizeof lies after "decay". Here it's still the real
    //    array (5 ints = 20 bytes)...
    cout << "sizeof(scores) in this scope = " << sizeof(scores) << " bytes\n";

    // ...but passed to a function, the array DECAYS to a bare pointer:
    decayDemo(scores);   // implicit int[5] -> int* conversion
}

// ═══════════════════════════════════════════════════════════════════════════
//  §2 · STATIC vs DYNAMIC — std::array and std::vector
//  Raw arrays are fine to know; in modern C++ you'll reach for these two.
// ═══════════════════════════════════════════════════════════════════════════
static void section2_stl_containers() {
    banner("§2 · STATIC vs DYNAMIC (STL)");

    // std::array — fixed size, known at compile time (a raw array in a
    // nicer package: knows its .size(), works with algorithms, never decays).
    array<int, 4> fixed = {10, 20, 30, 40};
    cout << "std::array: size=" << fixed.size()
         << "  front=" << fixed.front()
         << "  back=" << fixed.back() << '\n';

    // std::vector — THE dynamic array; the container you'll use 95% of the
    // time. It grows on demand by doubling its capacity:
    vector<int> v;
    cout << "\npush_back growth — watch capacity double:\n";
    for (int i = 1; i <= 9; ++i) {
        v.push_back(i * 10);
        cout << "  pushed " << setw(2) << i * 10
             << "   size=" << v.size()
             << "  capacity=" << v.capacity() << '\n';
    }
    // Doubling is WHY append is *amortized* O(1): the occasional O(n)
    // reallocation is spread across many cheap O(1) appends.

    // The everyday toolkit — know the cost of each call:
    v.pop_back();                 // O(1)  — remove the last element
    v.insert(v.begin() + 1, 99);  // O(n)  — shift everything after index 1
    v.erase(v.begin() + 1);       // O(n)  — shift left to close the gap
    v[0] = 7;                     // O(1)  — unchecked access
    cout << "\nafter ops: size=" << v.size()
         << "  v[0]=" << v.at(0) << '\n';

    // .at() = checked access: throws std::out_of_range instead of UB.
    try {
        (void)v.at(999);          // (void): we deliberately ignore the value
    } catch (const out_of_range&) {
        cout << "v.at(999) threw out_of_range — safe failure, not a crash\n";
    }
}

// ═══════════════════════════════════════════════════════════════════════════
//  §3 · CORE OPERATIONS — implement them once by hand and the
//  complexity table in the README makes perfect sense forever after.
// ═══════════════════════════════════════════════════════════════════════════

// LINEAR SEARCH — O(n) time, O(1) space.
// The only option on unsorted data: look at every element until found.
static int linearSearch(const vector<int>& a, int target) {
    for (int i = 0; i < (int)a.size(); ++i)  // cast: size() is unsigned
        if (a[i] == target) return i;        // first match wins
    return -1;                               // -1 = "not found" sentinel
}

// INSERT AT INDEX — O(n) time. Everything after `pos` shifts RIGHT.
//   [4, 8, 15, 16]  insert 99 at pos 2:
//   step 1: grow          [4, 8, 15, 16, _]
//   step 2: shift right   [4, 8, _, 15, 16]
//   step 3: place         [4, 8, 99, 15, 16]
static void insertAt(vector<int>& a, int pos, int value) {
    a.push_back(0);                          // grow by one slot
    for (int i = (int)a.size() - 1; i > pos; --i)
        a[i] = a[i - 1];                     // shift right, BACK to FRONT
    a[pos] = value;                          // drop the value in place
}

// DELETE AT INDEX — O(n) time. Everything after `pos` shifts LEFT.
static void deleteAt(vector<int>& a, int pos) {
    for (int i = pos; i < (int)a.size() - 1; ++i)
        a[i] = a[i + 1];                     // shift left, FRONT to BACK
    a.pop_back();                            // shrink by one slot
}

// REVERSE IN PLACE — O(n) time, O(1) extra space.
// Your first TWO-POINTER pattern: swap the ends, walk inward, meet in middle.
static void reverseInPlace(vector<int>& a) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo < hi) {
        swap(a[lo], a[hi]);
        ++lo; --hi;
    }
}

static void section3_operations() {
    banner("§3 · CORE OPERATIONS");
    vector<int> a = {4, 8, 15, 16, 23, 42};

    cout << "start:            "; print(a);

    cout << "linearSearch(23) -> index " << linearSearch(a, 23)
         << "                                    O(n)\n";
    cout << "linearSearch(99) -> " << linearSearch(a, 99)
         << " (not found)                          O(n)\n";

    insertAt(a, 2, 99);
    cout << "insertAt(2, 99):  "; print(a);  // [4 8 99 15 16 23 42]   O(n)

    deleteAt(a, 2);
    cout << "deleteAt(2):      "; print(a);  // [4 8 15 16 23 42]      O(n)

    reverseInPlace(a);
    cout << "reverseInPlace:   "; print(a);  // [42 23 16 15 8 4]      O(n)
}

// ═══════════════════════════════════════════════════════════════════════════
//  §4 · 2D ARRAYS — a matrix is "an array of arrays", stored ROW-MAJOR:
//  grid[1][2] lives at base + (1 * COLS + 2) * sizeof(int) — one flat block.
//  In interviews, a 2D grid IS a graph: each cell is a node, its neighbors
//  are up/down/left/right.
// ═══════════════════════════════════════════════════════════════════════════
static void section4_matrix() {
    banner("§4 · 2D ARRAYS (MATRICES)");

    int grid[3][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12}
    };

    cout << "grid[1][2] = " << grid[1][2] << "  (row 1, col 2 -> value 7)\n";

    // Traversal — O(rows x cols). The nested loop is the whole story.
    int sum = 0;
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 4; ++c)
            sum += grid[r][c];
    cout << "sum of all cells = " << sum << '\n';

    // The 4-direction trick every grid problem starts with. (dr, dc) pairs
    // let one loop check all neighbors — plus a BOUNDS CHECK, always.
    const int DR[] = {-1, 1,  0, 0};   // up, down, left, right (rows)
    const int DC[] = { 0, 0, -1, 1};   // (cols)
    int r = 1, c = 1;
    cout << "in-bounds neighbors of (1,1): ";
    for (int d = 0; d < 4; ++d) {
        int nr = r + DR[d], nc = c + DC[d];
        if (nr >= 0 && nr < 3 && nc >= 0 && nc < 4)   // stay inside the grid
            cout << '(' << nr << ',' << nc << ") ";
    }
    cout << '\n';
}

// ═══════════════════════════════════════════════════════════════════════════
//  §5 · THE FIVE ESSENTIAL ARRAY PATTERNS
//  Recognizing which pattern a problem wants is 80% of solving it.
// ═══════════════════════════════════════════════════════════════════════════

// PATTERN 1 · TWO POINTERS (sorted input) — find a pair summing to target.
// O(n) time, O(1) space — versus O(n^2) checking every pair.
static bool pairWithSum(const vector<int>& sorted, int target,
                        int& outI, int& outJ) {
    int lo = 0, hi = (int)sorted.size() - 1;
    while (lo < hi) {
        int sum = sorted[lo] + sorted[hi];
        if (sum == target) { outI = lo; outJ = hi; return true; }
        if (sum < target)  ++lo;   // sum too small -> need bigger values
        else               --hi;   // sum too big  -> need smaller values
    }
    return false;
}

// PATTERN 2 · SLIDING WINDOW (fixed size k) — max sum of k consecutive
// elements. Instead of re-summing each window (O(n*k)), SLIDE it:
// add the entering element, subtract the leaving one. O(n) time.
static int maxWindowSum(const vector<int>& a, int k) {
    int window = 0;
    for (int i = 0; i < k; ++i) window += a[i];   // build the first window
    int best = window;
    for (int i = k; i < (int)a.size(); ++i) {
        window += a[i] - a[i - k];                // slide: +new, -old
        best = max(best, window);
    }
    return best;
}

// PATTERN 3 · PREFIX SUM — answer many range-sum queries in O(1) each.
//   prefix[i] = a[0] + ... + a[i-1]      (prefix[0] = 0, one O(n) build)
//   sum of a[l..r]       = prefix[r+1] - prefix[l]
// long long guards against overflow on big sums.
static vector<long long> buildPrefix(const vector<int>& a) {
    vector<long long> p(a.size() + 1, 0);
    for (size_t i = 0; i < a.size(); ++i)
        p[i + 1] = p[i] + a[i];
    return p;
}

// PATTERN 4 · KADANE'S ALGORITHM — maximum subarray sum in a single pass.
// At each index ask one question: "extend the current run, or restart here?"
//   cur  = best subarray ENDING at i
//   best = best subarray seen anywhere so far        O(n) time, O(1) space
static int kadane(const vector<int>& a) {
    int best = a[0];
    int cur  = a[0];
    for (int i = 1; i < (int)a.size(); ++i) {
        cur  = max(a[i], cur + a[i]);   // restart at a[i]  vs  extend
        best = max(best, cur);
    }
    return best;
}

static void section5_patterns() {
    banner("§5 · THE FIVE ESSENTIAL PATTERNS");

    // 1 · two pointers — needs SORTED data
    vector<int> sorted = {2, 7, 11, 15, 19};
    int i = -1, j = -1;
    if (pairWithSum(sorted, 26, i, j))
        cout << "1. two pointers  : sorted[" << i << "]+sorted[" << j << "] = "
             << sorted[i] << "+" << sorted[j] << " = 26        O(n)\n";

    // 2 · sliding window — fixed size 3
    vector<int> prices = {4, 2, 1, 7, 5, 3, 8};
    cout << "2. sliding window: max sum of 3 consecutive = "
         << maxWindowSum(prices, 3) << " (5+3+8)                        O(n)\n";

    // 3 · prefix sums — instant range queries
    vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<long long> p = buildPrefix(a);
    int l = 2, r = 5;                                     // sum of a[2..5]
    cout << "3. prefix sum    : a[2..5] = " << (p[r + 1] - p[l])
         << " (4+1+5+9)                       O(1)/query\n";

    // 4 · Kadane — the classic maximum subarray
    vector<int> mixed = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "4. Kadane        : max subarray sum = " << kadane(mixed)
         << " (4-1+2+1)                        O(n)\n";

    // 5 · INDEX-AS-HASH — values in a small known range (1..6) let the
    //    ARRAY ITSELF be the frequency map. Faster than any hash map.
    vector<int> dice = {1, 3, 2, 1, 4, 1, 6, 3, 1};
    int count[7] = {0};                    // counts live at index 1..6
    for (int d : dice) ++count[d];         // one pass, direct addressing
    cout << "5. index-as-hash : dice frequencies = ";
    for (int face = 1; face <= 6; ++face)
        if (count[face]) cout << face << "x" << count[face] << ' ';
    cout << '\n';
}

// ═══════════════════════════════════════════════════════════════════════════
//  §6 · REAL-WORLD USE CASE — exam score analytics
//  A "dataset" is just an array; every statistic below is one or two
//  passes over it. This is arrays doing real work, end to end.
// ═══════════════════════════════════════════════════════════════════════════
static void section6_use_case() {
    banner("§6 · USE CASE · EXAM SCORE ANALYTICS");

    const vector<string> names = {"Ayesha", "Rakib", "Mim", "Sajid", "Tania"};
    vector<int> marks = {78, 92, 64, 85, 92};

    // 1 · Average — one O(n) pass. (0.0 start => double accumulate.)
    double avg = accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
    cout << fixed << setprecision(1);
    cout << "class average      : " << avg << " / 100\n";

    // 2 · Min & max — one O(n) pass each (or one combined pass).
    int lowest  = *min_element(marks.begin(), marks.end());
    int highest = *max_element(marks.begin(), marks.end());
    cout << "lowest / highest   : " << lowest << " / " << highest << '\n';

    // 3 · How many scored above average — one more O(n) pass.
    int above = 0;
    for (int m : marks)
        if (m > avg) ++above;
    cout << "above average      : " << above << " of " << marks.size() << '\n';

    // 4 · Toppers — scan for everyone who hit the max (ties included).
    cout << "topper(s)          : ";
    for (size_t k = 0; k < marks.size(); ++k)
        if (marks[k] == highest) cout << names[k] << ' ';
    cout << '(' << highest << ")\n";

    // 5 · Leaderboard — the "sort indices, not values" trick:
    //    build [0,1,2,...], then sort those positions by the mark they
    //    point at. Keeps names and marks perfectly aligned. stable_sort
    //    preserves the original order on ties (Rakib before Tania).
    vector<int> idx(names.size());
    iota(idx.begin(), idx.end(), 0);          // idx = {0, 1, 2, 3, 4}
    stable_sort(idx.begin(), idx.end(),
                [&](int x, int y) { return marks[x] > marks[y]; });

    cout << "leaderboard        :\n";
    int rank = 1;
    for (int k : idx)
        cout << "   " << rank++ << ". " << left << setw(7) << names[k]
             << marks[k] << '\n';
}

// ═══════════════════════════════════════════════════════════════════════════
//  main — run every section in order; compare the output with the comments.
// ═══════════════════════════════════════════════════════════════════════════
int main() {
    cout << "01 · ARRAYS — comprehensive C++ examples "
            "(data-structure/01-arrays)\n";

    section1_fundamentals();   // what arrays are + memory layout
    section2_stl_containers(); // std::array, std::vector, amortized growth
    section3_operations();     // search / insert / delete / reverse by hand
    section4_matrix();         // 2D grids + the 4-direction trick
    section5_patterns();       // two pointers, window, prefix, Kadane, index-as-hash
    section6_use_case();       // real-world analytics

    cout << "\nNext step: solve the problems listed in this folder's README.md "
            "into 01-arrays/problems/ — run them with:  ./run.sh 01-arrays/problems/<file>.cpp\n";
    return 0;
}
