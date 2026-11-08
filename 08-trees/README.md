# 08 · Trees

> A hierarchical structure of nodes: one root, every other node has exactly one parent — branches, leaves, and depth.

## 📖 Overview

- Built from **nodes** (value + children pointers); no cycles, fully connected.
- The most-asked interview family: binary trees, BSTs, N-ary trees, and balanced variants.
- Most tree problems are solved with **DFS (recursion)** or **BFS (queue)** — master the traversal, and half the problems solve themselves.

## 🔑 Key Terminology

| Term | Meaning |
|------|---------|
| Root / Leaf | Top node / nodes with no children |
| Parent / Child | Direct link up / down |
| Height | Longest downward path from a node to a leaf |
| Depth | Distance from the root down to a node |
| Balanced | Subtree heights differ by ≤ 1 everywhere |
| Full / Complete / Perfect | 0-or-2 children / left-packed levels / all levels full |

## 🔀 The Four Traversals

| Traversal | Order | Tool | Complexity |
|-----------|-------|------|:-----------:|
| Preorder | node → left → right | DFS | O(n) |
| Inorder | left → node → right | DFS | O(n) — **sorted for BSTs** |
| Postorder | left → right → node | DFS | O(n) |
| Level order | top level → bottom | BFS queue | O(n) |

Space: O(h) for DFS (h = height, log n balanced / n skewed), O(w) for BFS (widest level).

## ⏱️ Binary Search Tree (BST) Complexity

| Operation | Average | Worst (skewed) |
|-----------|:-------:|:--------------:|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Inorder traversal (sorted output) | O(n) | O(n) |

> Self-balancing trees (AVL, Red-Black) keep operations at O(log n) **guaranteed**.

**BST invariant:** everything in the left subtree < node < everything in the right subtree.

## 🎯 Essential Patterns

1. **DFS returning info upward** — each call returns height/sum/diameter to its parent (max depth, diameter).
2. **BFS level collection** — snapshot queue size per level for level-order lists.
3. **BST bounds validation** — pass down (min, max) limits to validate, or exploit inorder sortedness.
4. **LCA by value (BST)** vs. **LCA by subtree search (general tree)**.
5. **Global variable + helper** — many "best path" problems track a non-local max.
6. **Serialize with preorder + null markers** — rebuild exactly with the same order.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Maximum Depth of Binary Tree | 🟢 Easy | DFS |
| Invert Binary Tree | 🟢 Easy | Swap children |
| Same Tree | 🟢 Easy | Parallel DFS |
| Symmetric Tree | 🟢 Easy | Mirror DFS |
| Balanced Binary Tree | 🟢 Easy | Height check |
| Diameter of Binary Tree | 🟢 Easy | DFS + global max |
| Subtree of Another Tree | 🟢 Easy | Match at each node |
| Binary Tree Level Order Traversal | 🟡 Medium | BFS levels |
| Validate BST | 🟡 Medium | Bounds / inorder |
| Kth Smallest in BST | 🟡 Medium | Inorder counter |
| Lowest Common Ancestor of a BST | 🟡 Medium | Value walk |
| Construct Tree from Preorder & Inorder | 🟡 Medium | Root + split |
| Serialize and Deserialize Binary Tree | 🔴 Hard | Preorder + markers |
| Binary Tree Maximum Path Sum | 🔴 Hard | DFS + gain |

## 💡 Tips & Pitfalls

- An empty tree (`null` root) is valid — handle it before touching `root.val`.
- Skewed insertion order (sorted input) degrades a naive BST to a linked list — that's why balancing exists.
- Comparing "same tree" class problems: check `both null` → `one null` → `values` in that order.

## 🔗 Resources

- [VisuAlgo — Binary Search Tree](https://visualgo.net/en/bst)
- LeetCode Explore: [Binary Tree](https://leetcode.com/explore/learn/card/data-structure-tree/)
