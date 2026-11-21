#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isSafe(vector<string> &board, int row, int col) {
  int n = board.size();

  for (int r = 0; r < row; r++) {
    if (board[r][col] == 'Q')
      return false;
  }

  for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
    if (board[r][c] == 'Q')
      return false;
  }

  for (int r = row - 1, c = col + 1; r >= 0 && c < n; r--, c++) {
    if (board[r][c] == 'Q')
      return false;
  }

  return true;
}

void solve(vector<string> &board, int row) {
  int n = board.size();

  if (row == n) {
    for (string s : board)
      cout << s << endl;

    cout << endl;
    return;
  }

  for (int col = 0; col < n; col++) {
    if (!isSafe(board, row, col))
      continue;

    board[row][col] = 'Q';

    solve(board, row + 1);

    board[row][col] = '.';
  }
}

int main() {
  int n = 4;

  vector<string> board(n, string(n, '.'));

  solve(board, 0);
  return 0;
}