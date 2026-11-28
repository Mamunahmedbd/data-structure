#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
  unordered_map<char, Node *> children;
  bool isEnd = false;

  ~Node() {
    for (auto &p : children)
      delete p.second;
  }
};

class Trie {
  Node *root = new Node();

public:
  void insert(string word) {
    Node *current = root;

    for (char ch : word) {
      if (!current->children.count(ch))
        current->children[ch] = new Node();

      current = current->children[ch];
    }

    current->isEnd = true;
  }

  bool search(string word) {
    Node *current = root;

    for (char ch : word) {
      if (!current->children.count(ch))
        return false;

      current = current->children[ch];
    }

    return current->isEnd;
  }

  ~Trie() { delete root; }
};

int main() {
  Trie trie;

  trie.insert("Hello123");
  trie.insert("Computer");

  cout << boolalpha;
  cout << trie.search("Hello123") << endl;
  cout << trie.search("Hello") << endl;

  return 0;
}