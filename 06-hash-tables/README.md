# 06 · Hash Tables

> A structure that maps keys to values using a hash function — average **O(1)** insert, search, and delete.

## 📖 Overview

- A **hash function** converts a key into an array index (`hash(key) % capacity`), where the value is stored.
- Collisions (two keys, same index) are inevitable — resolved by **chaining** (linked lists per bucket) or **open addressing** (probe for the next free slot).
- The default "make it fast" tool: dictionaries (`dict`), maps (`HashMap`, `unordered_map`), objects, sets, caches.

## 🔑 Key Concepts

- **Hash function** — fast, deterministic, spreads keys uniformly.
- **Collision resolution** — chaining vs. linear/quadratic probing vs. double hashing.
- **Load factor** = entries / capacity; past a threshold (~0.7), the table **rehashes** into a bigger array — why operations are *amortized* O(1).
- **Worst case O(n)** — all keys colliding into one bucket (bad hash or adversarial input).
- **Keys must be hashable** — immutable values (numbers, strings, tuples), not lists.

## ⏱️ Time Complexity

| Operation | Average | Worst | Notes |
|-----------|:-------:|:-----:|-------|
| Search by key | **O(1)** | O(n) | All keys in one bucket |
| Insert | **O(1)** | O(n) | Amortized incl. rehash |
| Delete | **O(1)** | O(n) | — |
| Iterate all entries | O(n) | O(n) | Unordered! |
| Space | O(n) | O(n) | Extra for empty buckets |

## 🧩 Related Structures

| Structure | Property | Use |
|-----------|----------|-----|
| Hash map | key → value | Lookups, counting, grouping |
| Hash set | unique keys | Membership tests, dedupe |
| Ordered map (tree-based) | sorted keys, O(log n) | Range queries |
| LRU cache | hash map + doubly linked list | O(1) get/put with eviction |

## 🎯 Essential Patterns

1. **Seen set** — "have I met this before?" while scanning (duplicates, cycles).
2. **Frequency map** — count occurrences, then filter by count (anagrams, top-K warm-up).
3. **Index map** — store the last position of each value (Two Sum, duplicate distance).
4. **Prefix sum + hash map** — count subarrays with a given sum in O(n).
5. **Grouping by canonical key** — sort each item's characters; anagrams share a key.
6. **Complement lookup** — for each x, ask the map for `target − x` (turns O(n²) into O(n)).

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Two Sum | 🟢 Easy | Index map |
| Ransom Note | 🟢 Easy | Frequency count |
| Contains Duplicate II | 🟢 Easy | Index map |
| First Unique Character | 🟢 Easy | Frequency count |
| Design HashMap | 🟡 Medium | Build it yourself |
| Group Anagrams | 🟡 Medium | Canonical key |
| Top K Frequent Elements | 🟡 Medium | Count + heap |
| Insert Delete GetRandom O(1) | 🟡 Medium | Map + array swap |
| Longest Consecutive Sequence | 🟡 Medium | Set endpoints |
| Subarray Sum Equals K | 🟡 Medium | Prefix sum + map |

## 💡 Tips & Pitfalls

- Hash tables **remember nothing about order** — need sorted output? Sort the keys after.
- Space cost is real: an O(n) map is trading memory for speed — usually the right trade.
- Python tip: `defaultdict(int)` / `Counter` remove boilerplate counting code.
- Iterating a map while mutating it is undefined behavior in many languages — snapshot first.

## 🔗 Resources

- [How hash tables work — with visuals](https://www.freecodecamp.org/news/hash-tables/)
- LeetCode Explore: [Hash Table](https://leetcode.com/explore/learn/card/hash-table/)
