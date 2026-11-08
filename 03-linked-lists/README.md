# 03 · Linked Lists

> A chain of nodes where each node stores data and a pointer to the next node — elements live anywhere in memory, connected by links.

## 📖 Overview

- No random access: to reach the i-th node you must walk from the **head**, node by node.
- Grows and shrinks freely — no resizing, no shifting elements around on insert/delete.
- Trading arrays' O(1) access for O(1) insertion/deletion *when you're already at the position*.

## 🔑 Key Concepts

- **Node** — `data` + `next` (+ `prev` for doubly linked).
- **Head / Tail** — entry and exit points of the list.
- **Pointer rewiring** — insert/delete only reassign pointers, never shift data.
- **Traversal idiom** — `while (curr != null) { ...; curr = curr.next; }`.

## ⏱️ Time Complexity

| Operation | Complexity | Notes |
|-----------|:----------:|-------|
| Access i-th element | O(n) | Must walk from head |
| Search by value | O(n) | — |
| Insert at head | **O(1)** | Rewire head |
| Insert after a known node | **O(1)** | Pointer rewiring |
| Delete a known node (with prev) | **O(1)** | Bypass the node |
| Reverse | O(n) | In-place, O(1) extra space |
| Detect cycle | O(n) | Floyd's tortoise & hare |

## 🧩 Variants

| Type | Structure | Typical use |
|------|-----------|-------------|
| Singly linked | `next` only | Simple chains, stacks |
| Doubly linked | `next` + `prev` | Deques, LRU cache, browser history |
| Circular | Tail points back to head | Round-robin scheduling, buffers |

## 🎯 Essential Patterns

1. **Fast & Slow Pointers** — cycle detection, find middle (fast moves 2×).
2. **Dummy (Sentinel) Node** — a fake head removes "is it the head?" special cases.
3. **In-place Reversal** — `prev / curr / next` triplet rewiring.
4. **Two-List Merge** — splice nodes by comparison (merge sort on lists).
5. **Runner Technique** — a second pointer n steps behind (remove n-th from end).

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Reverse Linked List | 🟢 Easy | In-place reversal |
| Merge Two Sorted Lists | 🟢 Easy | Two-list merge |
| Linked List Cycle | 🟢 Easy | Fast & slow |
| Middle of the Linked List | 🟢 Easy | Fast & slow |
| Remove Duplicates from Sorted List | 🟢 Easy | Single pass |
| Remove Nth Node From End | 🟡 Medium | Two pointers gap |
| Add Two Numbers | 🟡 Medium | Digit-by-digit + carry |
| Copy List with Random Pointer | 🟡 Medium | Interleave clones |
| Reorder List | 🟡 Medium | Middle + reverse + merge |
| LRU Cache | 🟡 Medium | Hash map + doubly linked |
| Reverse Nodes in k-Group | 🔴 Hard | Grouped reversal |
| Merge k Sorted Lists | 🔴 Hard | Heap / divide & conquer |

## 💡 Tips & Pitfalls

- Always draw the pointer diagram **before** rewiring — order of assignments matters.
- Losing a `next` pointer mid-reversal is the classic memory-leak/bug source.
- Use a dummy head for delete/insert problems; return `dummy.next`.
- Doubly linked lists cost extra memory per node but give O(1) delete given the node.

## 🔗 Resources

- [VisuAlgo — Linked List visualization](https://visualgo.net/en/list)
- LeetCode Explore: [Linked List](https://leetcode.com/explore/learn/card/linked-list/)
