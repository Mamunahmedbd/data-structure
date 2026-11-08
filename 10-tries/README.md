# 10 · Tries (Prefix Trees)

> A tree where each path from the root spells a word — shared prefixes share branches.

## 📖 Overview

- A **trie** stores strings by their characters: each edge is a character, each node a prefix.
- Lookup, insert, and delete cost **O(k)** where k = the word's length — *independent of how many words are stored*.
- The engine behind autocomplete, spell-checkers, IP routing (binary tries), and T9-style input.

## 🔑 Key Concepts

- **Node anatomy** — children map (or array of 26) + `isEnd` flag marking a complete word.
- **Prefix sharing** — `"car"`, `"card"`, `"care"` share the `c-a-r` spine; memory shrinks when words overlap.
- **Search vs prefix search** — `search("car")` needs `isEnd`; `startsWith("ca")` just needs the path to exist.
- **Trade-off** — fast prefix operations in exchange for pointer-heavy nodes (more memory than a plain set of words).

## ⏱️ Time Complexity

| Operation | Complexity | Notes |
|-----------|:----------:|-------|
| Insert word | **O(k)** | Walk/create k nodes |
| Search exact word | **O(k)** | Path must exist + `isEnd` |
| Prefix search | **O(p)** | p = prefix length |
| Delete word | O(k) | Unmark / prune childless nodes |
| Space | O(total chars) worst case | Shared prefixes compress |

## 🧩 Variants

| Variant | Idea | Use |
|---------|------|-----|
| Array trie | `Node[26]` children | Fixed lowercase alphabet, fastest |
| Map trie | hash-map children | Any alphabet, Unicode |
| Compressed trie (radix) | Merge single-child chains | Fewer nodes, more code |
| Suffix trie/tree | All suffixes of a text | Substring queries |

## 🎯 Essential Patterns

1. **Insert & search skeleton** — walk char by char; create nodes as needed; set `isEnd` at the end.
2. **DFS from a trie node** — collect all words under a prefix (autocomplete): gather, then recurse into children.
3. **Trie + grid DFS** — search many words in a board at once: walk the trie as you walk the grid (Word Search II).
4. **Wildcard recursion** — on `'?'`/`'.'`, branch into *all* children instead of one.
5. **Length-ordered scan** — process words shortest-first when longer words may build on shorter ones.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Implement Trie (Prefix Tree) | 🟡 Medium | Build it yourself |
| Design Add and Search Words | 🟡 Medium | Wildcard recursion |
| Longest Word in Dictionary | 🟡 Medium | Build-up check |
| Replace Words | 🟡 Medium | Shortest prefix match |
| Search Suggestions System | 🟡 Medium | Prefix DFS |
| Map Sum Pairs | 🟡 Medium | Values on nodes |
| Word Search II | 🔴 Hard | Trie + grid DFS |

## 💡 Tips & Pitfalls

- Forgetting `isEnd` makes `"car"` report found when only `"cart"` was inserted.
- A map-based node (`dict` children) is fine to learn with; the 26-array version is faster for a-z only.
- Deleting safely means pruning nodes **bottom-up** only when they have no children and no `isEnd`.

## 🔗 Resources

- [Trie — VisuAlgo](https://visualgo.net/en/trie)
- [Tries explained with examples](https://www.geeksforgeeks.org/trie-insert-and-search/)
