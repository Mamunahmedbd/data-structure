# 14 · Greedy Algorithms

> Make the locally best choice at each step and never look back — when it works, it's unbeatably fast.

## 📖 Overview

- A greedy algorithm builds a solution piece by piece, choosing whatever looks best *right now*, without revisiting past choices.
- It doesn't always give the optimal answer — it must be **proved** valid for the problem (or tested against counterexamples).
- When valid, greedy usually runs in O(n log n) — dominated by an initial sort — versus DP's extra states.

## 🔑 Key Concepts

- **Greedy choice property** — a locally optimal choice leads to a globally optimal solution.
- **Optimal substructure** — the problem decomposes so that the remaining subproblem stays solvable greedily.
- **Exchange argument** — the standard proof: any optimal solution can be transformed into the greedy one without getting worse.
- **Counterexample testing** — try small adversarial inputs before trusting a greedy hunch (coin systems, interval clashes).
- Greedy vs DP: greedy commits; DP explores and compares. If a greedy choice can be "wrong later," you need DP.

## ⏱️ Typical Complexity

| Problem family | Approach | Complexity |
|----------------|----------|:----------:|
| Activity selection / max non-overlapping intervals | Sort by **end** + sweep | O(n log n) |
| Minimum arrows / rooms for intervals | Sort endpoints + counters | O(n log n) |
| Jump game (reachability / min jumps) | Greedy farthest-reach | O(n) |
| Fractional knapsack | Sort by value/weight ratio | O(n log n) |
| Task scheduling by frequency | Count + arrange | O(n log n) |
| Huffman coding | Min-heap merging | O(n log n) |

## 🎯 Essential Patterns

1. **Sort by end time** — to fit the most non-overlapping intervals, always take the interval that frees you earliest (activity selection).
2. **Two-pointer interval sweep** — sort starts and ends separately; advance whichever is smaller (meeting rooms II).
3. **Farthest-reach jumping** — treat jump progress like BFS layers over a growing window (jump game I/II).
4. **Last-occurrence expansion** — grow a chunk until it contains the last index of every char inside it (partition labels).
5. **Frequency-driven arranging** — place the most frequent items first, gap-fill the rest (task scheduler).
6. **Ratio sorting** — fractional knapsack: value ÷ weight descending.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Assign Cookies | 🟢 Easy | Sort + two pointers |
| Best Time to Buy and Sell Stock II | 🟢 Easy | Take every up-tick |
| Jump Game | 🟡 Medium | Farthest reach |
| Jump Game II | 🟡 Medium | Layered reach |
| Gas Station | 🟡 Medium | Circuit lemma |
| Partition Labels | 🟡 Medium | Last-occurrence expansion |
| Merge Triplets to Form Target | 🟡 Medium | Filter + greedy pick |
| Non-overlapping Intervals | 🟡 Medium | Sort by end, count removals |
| Minimum Number of Arrows to Burst Balloons | 🟡 Medium | Overlap greedy |
| Task Scheduler | 🟡 Medium | Frequency + idle gaps |
| Candy | 🔴 Hard | Two-directional sweep |

## 💡 Tips & Pitfalls

- **Sort order is the greedy.** Sorting by *start* vs *end* vs *length* completely changes correctness — think about which encodes "safest next choice."
- If you can't sketch a one-paragraph exchange argument, suspect the greedy and look for a counterexample (or switch to DP).
- Coin change is the canonical trap: greedy works for canonical coin systems but fails for sets like `{1, 3, 4}` (DP is required there).

## 🔗 Resources

- [Greedy algorithms — theory and proofs](https://www.geeksforgeeks.org/greedy-algorithms/)
- LeetCode Explore: [Greedy](https://leetcode.com/tag/greedy/)
