#include <iostream>
#include <string>
using namespace std;

struct Node {
  Node *children[26] = {};
  bool isEnd = false;

  ~Node() {
    for (Node *child : children)
      delete child;
  }
};

class WordDictionary {
  Node *root = new Node();

  bool dfs(Node *node, const string &word, int i) {
    if (!node)
      return false;

    if (i == word.size())
      return node->isEnd;

    char ch = word[i];

    if (ch == '.') {
      for (int j = 0; j < 26; j++) {
        if (dfs(node->children[j], word, i + 1))
          return true;
      }

      return false;
    }

    return dfs(node->children[ch - 'a'], word, i + 1);
  }

public:
  void addWord(string word) {
    Node *current = root;

    for (char ch : word) {
      int i = ch - 'a';

      if (!current->children[i])
        current->children[i] = new Node();

      current = current->children[i];
    }

    current->isEnd = true;
  }

  bool search(string word) { return dfs(root, word, 0); }

  ~WordDictionary() { delete root; }
};

int main() {
  WordDictionary wd;

  wd.addWord("bad");
  wd.addWord("dad");
  wd.addWord("mad");

  cout << boolalpha;

  cout << wd.search("pad") << endl;
  cout << wd.search("bad") << endl;
  cout << wd.search(".ad") << endl;
  cout << wd.search("b..") << endl;

  return 0;
}