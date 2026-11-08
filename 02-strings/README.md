# 02 · Strings

> A sequence of characters — think "array of chars" with special operations (compare, concat, search, slice).

## 📖 Overview

- In many languages (Java, Python, JavaScript) strings are **immutable** — every "modification" creates a new string. Use a char array / `StringBuilder` / `list` when mutating repeatedly.
- Characters are just numbers: `'a' = 97`, `'A' = 65`. `ch - 'a'` maps `'a'–'z'` to `0–25` — the basis of frequency arrays.
- Encodings matter: ASCII covers 128 characters; Unicode covers the world (UTF-8/UTF-16).

## 🔑 Key Concepts

- **Length & indexing** — `s[i]`, `len(s)`; last char is `s[n-1]`.
- **Substring vs subsequence** — substring is *contiguous*; subsequence may skip characters.
- **Palindrome** — reads the same forwards and backwards.
- **Anagram** — same characters with same frequencies, different order.
- **Frequency counting** — `int[26]` for lowercase letters beats a hash map.

## ⏱️ Time Complexity

| Operation | Complexity | Notes |
|-----------|:----------:|-------|
| Access char by index | **O(1)** | Like arrays |
| Traversal | O(n) | — |
| Concatenation | O(n + m) | Creates a new string |
| Slice / substring | O(k) | k = slice length (per-call) |
| Comparison | O(n) | Worst case |
| Search — naive | O(n · m) | n = text, m = pattern |
| Search — KMP | O(n + m) | Prefix-function based |
| Build from chars | O(n) | StringBuilder / list + join |

## 🧩 Variants & Representations

| Representation | Use case |
|----------------|----------|
| Char array / mutable list | Heavy in-place editing |
| Immutable string | Safe keys, hashing, caching |
| String builder | Repeated concatenation |
| Rolling hash / Rabin-Karp | Multiple pattern searches |

## 🎯 Essential Patterns

1. **Two Pointers from both ends** — palindrome checks, reversals.
2. **Sliding Window** — longest/shortest substring with a property (fixed or variable window).
3. **Frequency Map / Count Array** — anagrams, first unique char, duplicates.
4. **Expand Around Center** — palindromic substrings (2n − 1 centers).
5. **Prefix Function (KMP)** — fast pattern matching, period of a string.

## 🏋️ Practice Problems

| Problem | Difficulty | Pattern |
|---------|:----------:|---------|
| Valid Palindrome | 🟢 Easy | Two pointers |
| Valid Anagram | 🟢 Easy | Frequency count |
| Reverse String | 🟢 Easy | Two pointers |
| Longest Common Prefix | 🟢 Easy | Vertical scan |
| First Unique Character | 🟢 Easy | Frequency count |
| Longest Substring Without Repeating Characters | 🟡 Medium | Sliding window |
| Group Anagrams | 🟡 Medium | Canonical key |
| String to Integer (atoi) | 🟡 Medium | Parsing, edge cases |
| Longest Palindromic Substring | 🟡 Medium | Expand around center |
| Longest Repeating Character Replacement | 🟡 Medium | Sliding window |
| Palindromic Substrings | 🟡 Medium | Expand around center |
| Minimum Window Substring | 🔴 Hard | Sliding window |

## 💡 Tips & Pitfalls

- Concatenating in a loop (`s += ch`) is O(n²) in immutable-string languages — collect chars and `join`/`toString` at the end.
- Mind case sensitivity and non-alphanumeric characters before comparing.
- Empty string / single char are valid palindromes — handle edge cases explicitly.

## 🔗 Resources

- LeetCode Explore: [Arrays & Strings](https://leetcode.com/explore/learn/card/array-and-string/)
- [KMP algorithm explained](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
