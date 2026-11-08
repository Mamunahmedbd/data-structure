# 09 · Heaps & Priority Queues

> A complete binary tree where every parent beats its children — the min (or max) is always at the root, ready in O(1).

## 📖 Overview

- **Min-heap:** parent ≤ children → smallest element on top. **Max-heap:** the reverse.
- "Complete" means levels are filled left-to-right — which lets a heap live inside a **plain array** with no pointers.
- Powers **priority queues**, **heapsort**, **Dijkstra**, and every **top-K** problem.

## 🔑 Key Concepts

- **Array representation** — for index `i`: parent = `(i−1)/2`, children = `2i+1`, `2i+2`.
- **Sift up (heapify-up)** — after insert at the end, bubble it up: O(log n).
- **Sift down (heapify-down)** — after removing the root, move the last element to the top and bubble it down: O(log n).
- **Build-heap** — heapify an array bottom-up in **O(n)** (better than n inserts at O(n log n)).
- Heaps answer "min/max?" instantly but say nothing about overall order — only the root is special.

## ⏱️ Time Complexity

| Operation | Complexity | Notes |
|-----------|:----------:|-------|
| Peek min/max | **O(1)** | It's the root |
| Insert (push) | O(log n) | Sift up |
| Extract min/max (pop) | O(log n) | Sift down |
| Search arbitrary value | O(n) | Not a search structure |
| Build heap from array | **O(n)** | Bottom-up heapify |
| Heapsort | O(n log n) | Build + n extracts |

## 🧩 Variants

| Variant | Property | Use |
|---------|----------|-----|
| Min-heap | Smallest on top | K-largest, Dijkstra, merge |
| Max-heap | Largest on top | K-smallest, scheduling |
| Two heaps (min + max) | Balanced halves | Running median |
| Indexed heap | Supports decrease-key | Dijkstra with updates |

## 🎯 Essential Patterns

1. **Top-K with a size-K heap** — K largest elements → *min*-heap of size K (the heap holds "current best K"; its root is the first to evict).
2. **K-way merge** — heap of the heads of K sorted lists; pop the smallest, push its successor.
3. **Two heaps = median** — max-heap of the lower half + min-heap of the upper half, sizes within 1.
4. **Greedy with a max-heap** — repeatedly take the biggest/cheapest next action (task scheduler, rope merging).
5. **Streaming top-K** — a heap of size K handles unbounded streams in O(n log K) and O(K) space.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Kth Largest Element in a Stream | 🟢 Easy | Size-K min-heap |
| Last Stone Weight | 🟢 Easy | Max-heap simulation |
| Kth Largest Element in an Array | 🟡 Medium | Size-K heap / quickselect |
| K Closest Points to Origin | 🟡 Medium | Max-heap of K |
| Top K Frequent Elements | 🟡 Medium | Count + heap |
| Task Scheduler | 🟡 Medium | Greedy + max-heap |
| Design Twitter | 🟡 Medium | Merge feeds with heap |
| Find K Pairs with Smallest Sums | 🟡 Medium | K-way merge |
| Merge k Sorted Lists | 🔴 Hard | Heap of list heads |
| Find Median from Data Stream | 🔴 Hard | Two heaps |

## 💡 Tips & Pitfalls

- **Invert your instinct:** finding the K *largest* uses a *min*-heap — the root is the eviction candidate.
- Language heaps: Python `heapq` is min-only (negate values for a max-heap); Java has `PriorityQueue` with a comparator; C++ has `priority_queue` and `make_heap`.
- The heap is **not sorted** — never binary-search it or assume inorder anything.

## 🔗 Resources

- [VisuAlgo — Binary Heap visualization](https://visualgo.net/en/heap)
- [Heapify: why building is O(n)](https://courses.cs.washington.edu/courses/cse373/)
