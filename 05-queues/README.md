# 05 · Queues

> First-In, First-Out (FIFO): the first element enqueued is the first dequeued — like a line at a ticket counter.

## 📖 Overview

- Elements enter at the **rear** (`enqueue`) and leave from the **front** (`dequeue`) — both O(1).
- The natural structure for **fair processing order** and **breadth-first search (BFS)**.
- Real-world analogues: printer queues, message brokers, CPU scheduling, call-center hold lines.

## 🔑 Key Concepts

- **FIFO order** — preserves arrival order through processing.
- **Front / rear** — the only two touch points.
- **Circular queue (ring buffer)** — wraps indices around a fixed array; all operations O(1), no shifting.
- **Deque** — "double-ended queue": push/pop at **both** ends in O(1).
- **Priority queue** — elements leave by priority, not arrival (implemented with a heap — topic 09).

## ⏱️ Time Complexity

| Operation | Complexity | Notes |
|-----------|:----------:|-------|
| Enqueue | **O(1)** | Add at rear |
| Dequeue | **O(1)** | Remove from front |
| Peek front | **O(1)** | — |
| Search | O(n) | Must drain or scan |
| Monotonic deque query (max/min of window) | O(1) amortized | Sliding window maximum |

## 🧩 Variants

| Variant | Property | Typical use |
|---------|----------|-------------|
| Simple queue | FIFO | Order preservation, BFS |
| Circular queue | Fixed capacity, wraps around | Buffers, schedulers |
| Deque | Insert/delete both ends | Sliding windows, palindromes |
| Priority queue | Highest priority out first | Schedulers, Dijkstra, heaps |
| Monotonic deque | Kept sorted, both ends | Window max/min queries |

## 🎯 Essential Patterns

1. **BFS layer-by-layer** — process a queue until empty; each "level" is one loop iteration (trees, graphs, grids).
2. **Multi-source BFS** — seed the queue with several starting points (rot spreading from all rotten oranges).
3. **Sliding window maximum** — monotonic deque stores useful indices only.
4. **Queue via two stacks** — amortized FIFO from two LIFOs.
5. **Rate limiting / recent counter** — pop stale entries from the front while checking the window.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Implement Stack using Queues | 🟢 Easy | Rotation trick |
| Number of Recent Calls | 🟢 Easy | Shrink from front |
| Moving Average from Data Stream | 🟢 Easy | Fixed-size queue |
| Design Circular Queue | 🟡 Medium | Ring buffer |
| Rotting Oranges | 🟡 Medium | Multi-source BFS |
| Walls and Gates | 🟡 Medium | Multi-source BFS |
| Open the Lock | 🟡 Medium | BFS on states |
| Perfect Squares | 🟡 Medium | BFS shortest path |
| Design Hit Counter | 🟡 Medium | Queue + window |
| Sliding Window Maximum | 🔴 Hard | Monotonic deque |

## 💡 Tips & Pitfalls

- A plain array used naively as a queue (`pop from front`) costs O(n) per dequeue — use a proper queue, deque, or ring buffer.
- In BFS, mark nodes visited **when enqueuing** (not when dequeuing) or you'll enqueue duplicates.
- Level-by-level BFS: snapshot `queue.size()` at the start of each level.

## 🔗 Resources

- [VisuAlgo — Queue visualization](https://visualgo.net/en/list)
- LeetCode Explore: [Queue & Stack](https://leetcode.com/explore/learn/card/queue-stack/)
