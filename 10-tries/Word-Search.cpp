#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  Node *children[26] = {};
  string word = "";

  ~Node() {
    for (Node *child : children)
      delete child;
  }
};

class Solution {
  void insert(Node *root, const string &word) {
    for (char ch : word) {
      int i = ch - 'a';

      if (!root->children[i])
        root->children[i] = new Node();

      root = root->children[i];
    }

    root->word = word;
  }

  void dfs(vector<vector<char>> &board, int r, int c, Node *node,
           vector<string> &result) {

    int rows = board.size();
    int cols = board[0].size();

    if (r < 0 || c < 0 || r >= rows || c >= cols)
      return;

    char ch = board[r][c];

    if (ch == '#')
      return;

    int i = ch - 'a';

    if (!node->children[i])
      return;

    node = node->children[i];

    // Complete word found
    if (!node->word.empty()) {
      result.push_back(node->word);

      // Prevent duplicate results
      node->word = "";
    }

    // Mark visited
    board[r][c] = '#';

    dfs(board, r + 1, c, node, result);
    dfs(board, r - 1, c, node, result);
    dfs(board, r, c + 1, node, result);
    dfs(board, r, c - 1, node, result);

    // Undo visited
    board[r][c] = ch;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {

    vector<string> result;

    if (board.empty() || board[0].empty())
      return result;

    Node *root = new Node();

    for (string word : words)
      insert(root, word);

    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        dfs(board, r, c, root, result);
      }
    }

    delete root;

    return result;
  }
};

int main() {
  vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'}};

  vector<string> words = {"oath", "pea", "eat", "rain"};

  Solution solution;

  vector<string> result = solution.findWords(board, words);

  for (string word : result)
    cout << word << " ";

  return 0;
}