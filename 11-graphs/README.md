# 11 · Graphs

> A set of vertices (nodes) connected by edges (possibly weighted, possibly directed) — the structure of relationships.

## 📖 Overview

- Trees and linked lists are just special graphs. Graphs model maps, networks, dependencies, social circles, and grids.
- Two core traversals unlock most problems: **BFS** (queue, shortest unweighted path) and **DFS** (recursion/stack, components & structure).
- A 2D grid is a graph in disguise: each cell is a node; its neighbors are up/down/left/right.

## 🔑 Key Concepts

- **Directed vs undirected**, **weighted vs unweighted**.
- **Connected component** — a maximal group of mutually reachable nodes.
- **Cycle** — a path that returns to its start (DAG = directed, acyclic graph).
- **In-degree** — number of incoming edges (drives topological sorting).
- **Shortest path / MST** — classic weighted-graph problems with dedicated algorithms.

## 📐 Representations

| Representation | Space | Edge check | Iterate neighbors | Best for |
|----------------|:-----:|:----------:|:------------------:|----------|
| Adjacency list | O(V + E) | O(deg) | O(deg) | Sparse graphs (default choice) |
| Adjacency matrix | O(V²) | O(1) | O(V) | Dense / tiny graphs |
| Edge list | O(E) | O(E) | O(E) | Kruskal, simple input |

## ⏱️ Core Algorithm Complexities

| Algorithm | Complexity | Solves |
|-----------|:----------:|--------|
| BFS / DFS | **O(V + E)** | Traversal, components, shortest unweighted path |
| Topological sort (Kahn's / DFS) | O(V + E) | Dependency order on DAGs |
| Union-Find (DSU) | ≈ O(α(n)) per op | Dynamic connectivity, cycle in undirected |
| Dijkstra (heap) | O((V + E) log V) | Shortest path, non-negative weights |
| Bellman-Ford | O(V · E) | Shortest path with negative edges |
| Floyd-Warshall | O(V³) | All-pairs shortest paths |
| Kruskal / Prim | O(E log V) | Minimum spanning tree |

## 🎯 Essential Patterns

1. **Flood fill** — DFS/BFS from a cell, recolor as visited (islands, area counting).
2. **Level BFS = shortest path** — unweighted distances are BFS levels; multi-source BFS starts from many nodes at once.
3. **Topological sort** — repeatedly take zero-in-degree nodes (course scheduling, build order); leftover edges = cycle.
4. **Union-Find** — merge sets while scanning edges; count components or detect cycles without building the graph.
5. **Grid → graph** — treat each cell as a node; bounds-check the 4 (or 8) neighbors; mark visited in place.
6. **State-space search** — BFS over *states* (locks, strings, board configurations), not literal nodes.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Number of Islands | 🟡 Medium | Flood fill |
| Max Area of Island | 🟡 Medium | Flood fill + size |
| Clone Graph | 🟡 Medium | DFS/BFS + hash map |
| Course Schedule | 🟡 Medium | Topological sort |
| Course Schedule II | 🟡 Medium | Topological order |
| Number of Connected Components | 🟡 Medium | Union-Find / DFS |
| Graph Valid Tree | 🟡 Medium | n−1 edges + connected |
| Pacific Atlantic Water Flow | 🟡 Medium | Reverse multi-source DFS |
| Rotting Oranges | 🟡 Medium | Multi-source BFS |
| Network Delay Time | 🟡 Medium | Dijkstra |
| Min Cost to Connect All Points | 🟡 Medium | MST |
| Word Ladder | 🔴 Hard | BFS on states |
| Alien Dictionary | 🔴 Hard | Topological sort |

## 💡 Tips & Pitfalls

- **Mark visited when enqueuing** (BFS) or on entry (DFS) — never twice-visit.
- BFS gives the shortest path **only when all edges have equal weight**; weighted → Dijkstra.
- Directed vs undirected changes everything: add one edge or two, cycle rules differ.
- Recursive DFS on a huge grid can overflow the stack — switch to an explicit stack.

## 🔗 Resources

- [VisuAlgo — Graph traversal](https://visualgo.net/en/dfsbfs)
- LeetCode Explore: [Graph](https://leetcode.com/explore/learn/card/graph/)
