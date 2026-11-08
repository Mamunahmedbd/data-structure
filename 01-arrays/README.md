# 01 · Arrays

> A contiguous block of memory holding elements of the same type, accessed by index — the simplest and most used data structure.

## 📖 Overview

- Elements sit **next to each other in memory**, which is why index access is instant: `address = base + index × element_size`.
- **Fixed size** in low-level languages (C/C++ arrays); higher-level languages offer *dynamic arrays* (`vector`, `list`, `ArrayList`) that resize by doubling capacity.
- Best fit for: fast reads by position, iteration, and as the backing store for stacks, queues, and heaps.

## 🔑 Key Concepts

- **Indexing** — zero-based in most languages; `arr[0]` is the first element.
- **Traversal** — visiting each element once: O(n).
- **In-place operations** — swapping/reversing with two indices, no extra memory.
- **2D arrays (matrices)** — arrays of arrays; `grid[i][j]`, row-major layout.
- **Dynamic array growth** — append is amortized O(1): doubling capacity makes resizes rare.

## ⏱️ Time Complexity

| Operation | Complexity | Notes |
|-----------|:----------:|-------|
| Access by index | **O(1)** | Direct memory offset |
| Search (unsorted) | O(n) | Linear scan |
| Search (sorted) | O(log n) | Binary search |
| Insert / delete at end | **O(1)** | Amortized for dynamic arrays |
| Insert / delete at arbitrary position | O(n) | Shifting elements |
| Traversal | O(n) | — |
| Sorting | O(n log n) | Comparison-based best |

## 🧩 Variants

| Variant | Description |
|---------|-------------|
| Static array | Fixed size, allocated upfront |
| Dynamic array | Auto-resizes (Python `list`, C++ `vector`, Java `ArrayList`) |
| 1D / 2D / 3D | Linear list, matrix, tensor-like grids |
| Jagged array | Array of arrays with unequal row lengths |

## 🎯 Essential Patterns

1. **Two Pointers** — pointers from both ends moving inward (pair sums, palindromes, container problems).
2. **Sliding Window** — expand/contract a subarray window for substring/subarray questions.
3. **Prefix Sum** — precompute running sums so any range sum is O(1).
4. **Kadane's Algorithm** — maximum subarray sum in one pass.
5. **Sort First** — sorting often unlocks two-pointer/binary-search approaches.
6. **Index as Hash** — when values are bounded (e.g. 0…n), use the array itself as a frequency/flag map.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Two Sum | 🟢 Easy | Hash map |
| Best Time to Buy and Sell Stock | 🟢 Easy | One pass |
| Contains Duplicate | 🟢 Easy | Hash set |
| Missing Number | 🟢 Easy | Sum / XOR |
| Maximum Subarray | 🟡 Medium | Kadane's |
| Product of Array Except Self | 🟡 Medium | Prefix/suffix products |
| Merge Intervals | 🟡 Medium | Sort + sweep |
| Rotate Array | 🟡 Medium | Reversal trick |
| Container With Most Water | 🟡 Medium | Two pointers |
| Sort Colors | 🟡 Medium | Dutch national flag |
| Trapping Rain Water | 🔴 Hard | Two pointers / prefix max |

## 💡 Tips & Pitfalls

- **Off-by-one errors** are the #1 bug source — be careful with `<` vs `<=` and `mid ± 1`.
- Compute mid overflow-safely: `mid = low + (high - low) / 2`.
- Insert/delete in the middle is O(n) — if you need frequent middle inserts, a linked list may fit better.
- Hidden O(n²): calling `.index()` / `.contains()` inside a loop.

## 🔗 Resources

- [VisuAlgo — Array visualization](https://visualgo.net/en/list)
- LeetCode Explore: [Arrays 101](https://leetcode.com/explore/learn/card/fun-with-arrays/)
