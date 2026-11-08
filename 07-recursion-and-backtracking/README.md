# 07 · Recursion & Backtracking

> A function that calls itself on smaller inputs — and backtracking: undo a choice, try the next one.

## 📖 Overview

- Every recursive function needs a **base case** (stop) and a **recursive case** (shrink the problem).
- Each call gets its own stack frame — **space = recursion depth**, and deep recursion can overflow the stack.
- **Backtracking** = recursion over *choices*: choose → explore → **undo** → choose differently. It walks a decision tree, usually O(2ⁿ) or O(n!) — pruned aggressively when possible.

## 🔑 Key Concepts

- **Base case & recursive case** — the two non-negotiables.
- **Call stack** — frames pile up per call; depth costs memory.
- **Recursion tree** — draw it to reason about time complexity (branching factor ^ depth).
- **State** — what the current path looks like (choices made so far).
- **Pruning** — abandon branches early that can't succeed (sort + skip duplicates; bounds checks).
- **Memoization preview** — same subproblem recomputed? That's dynamic programming (topic 15).

## ⏱️ Complexity of Common Shapes

| Shape | Time | Example |
|-------|:----:|---------|
| One branch, depth n | O(n) | Factorial, list traversal |
| Two branches, depth n | O(2ⁿ) | Fibonacci (naive), subsets |
| n branches, depth n | O(n!) | Permutations |
| Halving, depth log n | O(log n) | Binary search recursion |
| Space (any) | O(depth) | Call stack |

## 🎯 Essential Patterns

1. **Include / Exclude** — for each element: take it or skip it → all subsets.
2. **Permutation template** — used[] marks taken items; place each unused item next.
3. **Backtracking template** — `choose → recurse → un-choose`; classic three lines at the heart of every solution.
4. **Grid DFS + visited** — mark, explore 4 directions, unmark (word search).
5. **Constraint-driven pruning** — parens balance, remaining sum, board validity (N-Queens, Sudoku).

```text
backtrack(state):
    if goal(state):        record; return
    for choice in options(state):
        if invalid(choice): continue      # prune
        apply(choice)                     # choose
        backtrack(state)                  # explore
        undo(choice)                      # un-choose
```

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Fibonacci Number | 🟢 Easy | Basic recursion → memo |
| Pow(x, n) | 🟡 Medium | Fast exponentiation |
| Subsets | 🟡 Medium | Include / exclude |
| Subsets II | 🟡 Medium | Sort + skip duplicates |
| Permutations | 🟡 Medium | Choice template |
| Combination Sum | 🟡 Medium | Retry elements |
| Combination Sum II | 🟡 Medium | Skip duplicates |
| Letter Combinations of a Phone Number | 🟡 Medium | Multi-way choice |
| Generate Parentheses | 🟡 Medium | Constraint pruning |
| Palindrome Partitioning | 🟡 Medium | Cut + recurse |
| Word Search | 🟡 Medium | Grid DFS + undo |
| N-Queens | 🔴 Hard | Row-by-row + validity |
| Sudoku Solver | 🔴 Hard | Constraint backtracking |

## 💡 Tips & Pitfalls

- No base case = infinite recursion = stack overflow. Write the base case **first**.
- In backtracking, forgetting to **undo** the choice corrupts every later branch.
- If the recursion tree repeats states, add memoization — you may have discovered DP.
- Converting to iteration (explicit stack) removes stack-overflow risk for deep searches.

## 🔗 Resources

- [Recursion visualized — VisuAlgo](https://visualgo.net/en/recursion)
- LeetCode Explore: [Recursion I & II](https://leetcode.com/explore/learn/card/recursion-i/)
