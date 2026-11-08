# 12 · Sorting Algorithms

> Rearranging elements into order — the classic study of trade-offs: time vs space vs stability.

## 📖 Overview

- Every language ships a built-in sort (usually Timsort or introsort) — knowing the **algorithms** is about trade-off intuition and interviews.
- Comparison sorts can't beat **Ω(n log n)** in the worst case; non-comparison sorts (counting, radix) beat it under special conditions.
- Stability matters when sorting by one key while preserving a previous order (e.g., sort by name, then by department — the second sort must be stable).

## 📊 The Full Comparison Table

| Algorithm | Best | Average | Worst | Space | Stable? | One-line idea |
|-----------|:----:|:-------:|:-----:|:-----:|:-------:|---------------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | ✅ | Repeatedly swap adjacent out-of-order pairs |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | ❌ | Select the min, place it at the front |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | ✅ | Grow a sorted prefix; insert each new card |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ | Sort halves, merge them |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ | Partition around a pivot, recurse |
| Heap | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ | Build a heap, extract max repeatedly |
| Counting | O(n+k) | O(n+k) | O(n+k) | O(k) | ✅ | Count occurrences per value |
| Radix | O(n·k) | O(n·k) | O(n·k) | O(n+k) | ✅ | Sort digit by digit (stable passes) |
| Bucket | O(n+k) | O(n+k) | O(n²) | O(n) | ✅ | Scatter into buckets, sort each |

*(k = value range or digit count)*

## 🎯 When to Use What

| Situation | Reach for |
|-----------|-----------|
| Small or nearly-sorted data | Insertion sort |
| Guaranteed O(n log n) + stable | Merge sort |
| Fast in practice, in-place-ish | Quick sort |
| Guaranteed O(n log n) + O(1) space | Heap sort |
| Integers in a small range | Counting sort |
| Long numbers / fixed-width keys | Radix sort |
| Uniformly distributed floats | Bucket sort |

## 🔑 Key Concepts

- **In-place** — O(1) extra memory.
- **Stable** — equal keys keep their original relative order.
- **Comparison-sort lower bound** — Ω(n log n) decision-tree argument.
- **Quickselect** — partition logic reused to find the k-th element in O(n) average.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Sort Colors | 🟡 Medium | Dutch national flag (3-way partition) |
| Merge Intervals | 🟡 Medium | Sort by start + sweep |
| Meeting Rooms | 🟢 Easy | Sort intervals, check overlap |
| Meeting Rooms II | 🟡 Medium | Sort starts & ends, two pointers |
| Sort List | 🟡 Medium | Merge sort on linked list |
| Largest Number | 🟡 Medium | Custom comparator |
| Sort Characters By Frequency | 🟡 Medium | Count + bucket sort |
| Kth Largest Element | 🟡 Medium | Quickselect / heap |

## 💡 Tips & Pitfalls

- Implement **merge, quick, insertion** from memory — they cover 90% of interviews.
- Quick sort's worst case comes from bad pivots on sorted input — randomize or median-of-three.
- A comparator must be a **consistent** total order (`a≤b` and `b≤a` implies equal), or sorts misbehave.

## 🔗 Resources

- [VisuAlgo — Sorting visualized](https://visualgo.net/en/sorting)
- [Sorting algorithms — Side-by-side comparisons](https://www.toptal.com/developers/sorting-algorithms)
