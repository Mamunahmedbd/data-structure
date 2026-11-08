# 04 · Stacks

> Last-In, First-Out (LIFO): the last element pushed is the first one popped — like a stack of plates.

## 📖 Overview

- Only the **top** is accessible: `push`, `pop`, `peek` — all O(1).
- Naturally models anything that *undoes* or *nests*: function calls, browser back button, brackets, undo history.
- The **call stack** in every program is a stack — recursion (topic 07) literally runs on one.

## 🔑 Key Concepts

- **LIFO order** — reverses whatever you feed through it.
- **Underflow / overflow** — popping an empty stack; pushing to a bounded one.
- **Balanced nesting** — every opener must meet its closer in the reverse order it opened.
- **Monotonic stack** — kept sorted (increasing/decreasing); the key to "next greater/smaller element" problems.

## ⏱️ Time Complexity

| Operation | Complexity | Notes |
|-----------|:----------:|-------|
| Push | **O(1)** | Add to top |
| Pop | **O(1)** | Remove from top |
| Peek / Top | **O(1)** | Look at top |
| Search | O(n) | Must pop through |
| Space | O(n) | Grows with pushes |

## 🧩 Variants & Implementations

| Implementation | Notes |
|----------------|-------|
| Array-backed | Simple; amortized O(1) push via dynamic array |
| Linked-list-backed | True O(1) push/pop, extra pointer memory |
| Min-stack | Auxiliary stack tracks the current minimum |
| Monotonic stack | Elements kept in sorted order while pushing/popping |

## 🎯 Essential Patterns

1. **Matching Pairs** — push openers, pop on closers (valid parentheses).
2. **Monotonic Stack** — pop while top is "worse"; what remains answers next-greater/smaller queries.
3. **Expression Evaluation** — postfix (RPN) evaluation; infix → postfix (shunting-yard).
4. **Undo / Backtracking state** — push state, pop to restore (pairs with topic 07).
5. **Stack + Greedy digit removal** — remove K digits: pop while a smaller digit can improve the result.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Valid Parentheses | 🟢 Easy | Matching pairs |
| Next Greater Element I | 🟢 Easy | Monotonic stack |
| Implement Queue using Stacks | 🟢 Easy | Two stacks |
| Baseball Game | 🟢 Easy | Simulation |
| Min Stack | 🟡 Medium | Auxiliary stack |
| Evaluate Reverse Polish Notation | 🟡 Medium | Postfix evaluation |
| Daily Temperatures | 🟡 Medium | Monotonic stack |
| Simplify Path | 🟡 Medium | Stack of path parts |
| Remove K Digits | 🟡 Medium | Greedy + stack |
| Car Fleet | 🟡 Medium | Sort + stack |
| Generate Parentheses | 🟡 Medium | Backtracking (topic 07) |
| Largest Rectangle in Histogram | 🔴 Hard | Monotonic stack |

## 💡 Tips & Pitfalls

- Check for emptiness **before** popping — underflow crashes or returns garbage.
- A monotonic stack problem usually whispers: *"for each element, find the nearest bigger/smaller one"*.
- Reversing with a stack costs O(n) extra space — in-place reversal (arrays/lists) is often better.

## 🔗 Resources

- [VisuAlgo — Stack visualization](https://visualgo.net/en/stack)
- [Monotonic stack pattern guide](https://labuladong.gitbook.io/algorithms)
