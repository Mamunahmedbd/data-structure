#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
  TrieNode *children[26];
  bool isEnd;

  TrieNode() {
    isEnd = false;

    for (int i = 0; i < 26; i++)
      children[i] = nullptr;
  }

  ~TrieNode() {
    for (int i = 0; i < 26; i++)
      delete children[i];
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *current = root;

    for (char ch : word) {
      int index = ch - 'a';

      if (current->children[index] == nullptr) {
        current->children[index] = new TrieNode();
      }

      current = current->children[index];
    }

    current->isEnd = true;
  }

  bool search(string word) {
    TrieNode *current = root;

    for (char ch : word) {
      int index = ch - 'a';

      if (current->children[index] == nullptr)
        return false;

      current = current->children[index];
    }

    return current->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode *current = root;

    for (char ch : prefix) {
      int index = ch - 'a';

      if (current->children[index] == nullptr)
        return false;

      current = current->children[index];
    }

    return true;
  }

  ~Trie() { delete root; }
};

int main() {
  Trie trie;

  trie.insert("apple");
  trie.insert("banana");

  cout << boolalpha;

  cout << trie.search("apple") << endl;
  cout << trie.search("app") << endl;
  cout << trie.startsWith("app") << endl;

  trie.insert("app");

  cout << trie.search("app") << endl;

  return 0;
}