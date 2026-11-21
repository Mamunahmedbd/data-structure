#include <iostream>
#include <vector>
using namespace std;

bool valid(vector<vector<char>> &b, int r, int c, char x) {
  for (int i = 0; i < 9; i++) {
    if (b[r][i] == x || b[i][c] == x)
      return false;

    int br = 3 * (r / 3) + i / 3;
    int bc = 3 * (c / 3) + i % 3;

    if (b[br][bc] == x)
      return false;
  }

  return true;
}

bool solve(vector<vector<char>> &b) {
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      if (b[r][c] != '.')
        continue;

      for (char x = '1'; x <= '9'; x++) {
        if (!valid(b, r, c, x))
          continue;

        b[r][c] = x;

        if (solve(b))
          return true;

        b[r][c] = '.';
      }

      return false;
    }
  }

  return true;
}

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  if (solve(board)) {
    for (auto row : board) {
      for (char x : row)
        cout << x << " ";
      cout << endl;
    }
  }

  return 0;
}