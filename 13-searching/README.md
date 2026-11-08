# 13 · Searching Algorithms

> Finding an element — linear scan for anything, binary search for order.

## 📖 Overview

- **Linear search** works everywhere, costs O(n).
- **Binary search** needs sorted (or monotone) input and finds in O(log n) — a million elements in ~20 steps.
- The deeper skill: recognizing **monotonic structure** — "binary search on the answer" solves a surprising family of optimization problems.

## 🔑 Key Concepts

- **Loop invariant** — what stays true each iteration (target always within `[low, high]`).
- **Lower / upper bound** — first index with value ≥ x (or > x): the basis of range queries.
- **Overflow-safe mid** — `mid = low + (high - low) / 2`.
- **Monotone predicate** — a yes/no question where once true it stays true (or vice versa) — binary searchable.
- **Rotated sorted arrays** — one half is always sorted; use it to decide which side to search.

## ⏱️ Time Complexity

| Algorithm | Best | Average | Worst | Space | Requirement |
|-----------|:----:|:-------:|:-----:|:-----:|-------------|
| Linear search | O(1) | O(n) | O(n) | O(1) | None |
| Binary search (iterative) | O(1) | O(log n) | O(log n) | **O(1)** | Sorted input |
| Binary search (recursive) | O(1) | O(log n) | O(log n) | O(log n) | Sorted input |
| Binary search on 2D matrix | — | O(log (m·n)) | O(log (m·n)) | O(1) | Row-major sorted |
| Search on answer | — | O(n log R) | O(n log R) | O(1) | Monotone feasibility |

## 🎯 Essential Patterns

1. **Classic template** — `while (low <= high)` with exact match; shrink with `mid ± 1`.
2. **Find first/last occurrence** — keep searching *after* a hit (`low = mid + 1` / `high = mid − 1`) while recording the answer.
3. **Rotated array** — compare `nums[low] <= nums[mid]` to identify the sorted half; then range-check the target.
4. **Binary search on the answer** — if `feasible(x)` is monotone in x, binary-search x over [min, max] (speeds, capacities, sizes).
5. **2D matrices** — treat rows as one long sorted array, or eliminate a row/column per step from a corner.

```text
low, high = 0, n - 1
while low <= high:
    mid = low + (high - low) // 2
    if arr[mid] == target: return mid
    elif arr[mid] < target: low = mid + 1
    else: high = mid - 1
return -1
```

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Binary Search | 🟢 Easy | Classic template |
| Search Insert Position | 🟢 Easy | Lower bound |
| First Bad Version | 🟢 Easy | Monotone predicate |
| Find Minimum in Rotated Sorted Array | 🟡 Medium | Unsorted-side minimum |
| Search in Rotated Sorted Array | 🟡 Medium | Sorted half check |
| Find First and Last Position | 🟡 Medium | First/last occurrence |
| Search a 2D Matrix | 🟡 Medium | Virtual 1D array |
| Search a 2D Matrix II | 🟡 Medium | Staircase from corner |
| Find Peak Element | 🟡 Medium | Slope direction |
| Koko Eating Bananas | 🟡 Medium | Search on answer |
| Capacity to Ship Packages | 🟡 Medium | Search on answer |
| Median of Two Sorted Arrays | 🔴 Hard | Partition binary search |

## 💡 Tips & Pitfalls

- Ninety percent of binary-search bugs are boundary bugs — decide `<` vs `<=` and `mid` vs `mid ± 1` before writing.
- "Minimize the maximum / maximize the minimum" is a giant neon sign pointing at **search on the answer**.
- Duplicates in a rotated array break the clean half-selection — handle `nums[low] == nums[mid]` separately.

## 🔗 Resources

- [Binary search — the whole picture](https://leetcode.com/explore/learn/card/binary-search/)
- [Binary search — GeeksforGeeks](https://www.geeksforgeeks.org/binary-search/)
