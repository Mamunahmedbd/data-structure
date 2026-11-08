# 15 · Dynamic Programming

> Solve each subproblem once, store the answer, reuse it — the art of recognizing overlapping subproblems.

## 📖 Overview

- DP applies when a problem has **overlapping subproblems** (same smaller cases recur) and **optimal substructure** (an optimal answer builds from optimal sub-answers).
- Two styles: **memoization** (top-down recursion + cache) and **tabulation** (bottom-up table filling).
- The hardest part is always the same: **defining the state** — what a table cell *means*. Get `dp[i]` right and the transitions usually write themselves.

## 🔑 Key Concepts

- **State** — the minimal description of a subproblem (`dp[i]`, `dp[i][j]`, `dp[i][w]`, …).
- **Transition** — how bigger states are built from smaller ones (the recurrence).
- **Base cases** — the states you can answer directly; the foundation of the table.
- **Iteration order** — fill dependencies before dependents.
- **Space optimization** — if `dp[i]` needs only row `i−1`, keep two rows (or one) instead of the full table.
- **Complexity = number of states × cost per transition.**

## 📐 The DP Recipe

1. Solve a small example **by hand**; watch which subproblems repeat.
2. Define the state in plain words ("`dp[i]` = best answer using the first i items").
3. Write the recurrence — relate a state to smaller states.
4. Pin down base cases and the answer's location (`dp[n]`? max over row?).
5. Implement top-down (memo) first; convert to bottom-up if needed.
6. Optimize space last, only if required.

## 🧩 The Classic Families

| Family | State shape | Signature problems |
|--------|-------------|--------------------|
| 1D linear | `dp[i]` | Climbing stairs, house robber, max subarray |
| 2D grid | `dp[i][j]` | Unique paths, min path sum |
| 0/1 knapsack | `dp[i][w]` | Subset sum, partition equal subset |
| Unbounded knapsack | `dp[w]` | Coin change I & II |
| Longest increasing subsequence | `dp[i]` (or patience O(n log n)) | LIS, Russian dolls |
| Two-sequence (LCS family) | `dp[i][j]` | LCS, edit distance |
| Interval DP | `dp[i][j]` over ranges | Burst balloons, matrix chain |
| State machine | `dp[i][holding]` | Stock series |
| Bitmask DP | `dp[mask]` | TSP-style, small n ≤ ~20 |

## ⏱️ Complexity at a Glance

| Pattern | Time | Space (optimizable) |
|---------|:----:|:-------------------:|
| 1D DP | O(n) | O(n) → O(1) |
| 2D grid DP | O(m·n) | O(m·n) → O(n) |
| Knapsack | O(n·W) | O(W) |
| LCS / edit distance | O(m·n) | O(min(m,n)) |
| LIS (DP version / patience) | O(n²) / O(n log n) | O(n) |
| Interval DP | O(n³) | O(n²) |
| Bitmask DP | O(2ⁿ · n) | O(2ⁿ) |

## 🏋️ Practice Problems

| Problem | Difficulty | Family |
|---------|:----------:|--------|
| Climbing Stairs | 🟢 Easy | 1D |
| Min Cost Climbing Stairs | 🟢 Easy | 1D |
| House Robber | 🟡 Medium | 1D |
| House Robber II | 🟡 Medium | 1D (circular) |
| Coin Change | 🟡 Medium | Unbounded knapsack |
| Coin Change II | 🟡 Medium | Unbounded knapsack (count) |
| Longest Increasing Subsequence | 🟡 Medium | LIS |
| Longest Common Subsequence | 🟡 Medium | Two sequences |
| Edit Distance | 🟡 Medium | Two sequences |
| Unique Paths | 🟡 Medium | 2D grid |
| Word Break | 🟡 Medium | 1D + dictionary |
| Decode Ways | 🟡 Medium | 1D |
| Maximum Product Subarray | 🟡 Medium | 1D (keep min & max) |
| Partition Equal Subset Sum | 🟡 Medium | 0/1 knapsack |
| Best Time to Buy/Sell Stock with Cooldown | 🟡 Medium | State machine |
| Burst Balloons | 🔴 Hard | Interval DP |
| Regular Expression Matching | 🔴 Hard | Two sequences |

## 💡 Tips & Pitfalls

- Start **top-down with memoization** — it's the recursive brute force you already understand, plus a cache.
- A wrong state definition can't be fixed by clever transitions — re-articulate what `dp[i]` means before debugging code.
- Knapsack space trick: iterate weights **downward** for 0/1 (each item once), **upward** for unbounded.
- If your "DP" never reuses a state, it's just plain recursion — check for overlaps first.

## 🔗 Resources

- [DP from beginner to advanced — freeCodeCamp](https://www.freecodecamp.org/news/learn-dynamic-programing-to-solve-coding-challenges/)
- LeetCode Explore: [Dynamic Programming](https://leetcode.com/explore/learn/card/dynamic-programming/)
