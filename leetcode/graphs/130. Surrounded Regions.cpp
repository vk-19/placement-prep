// @author: Vineet Kumar
// @user: vk-19
// Link: https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
  int rows, cols;

  void dfs(vector<vector<char>> &board, int i, int j) {
    if (board[i][j] == 'O') {
      board[i][j] = 'I';

      // top
      if (i - 1 >= 0) {
        dfs(board, i - 1, j);
      }

      // right
      if (j + 1 < cols) {
        dfs(board, i, j + 1);
      }

      // bottom
      if (i + 1 < rows) {
        dfs(board, i + 1, j);
      }

      // left
      if (j - 1 >= 0) {
        dfs(board, i, j - 1);
      }
    }
  }

  void solve(vector<vector<char>> &board) {
    rows = board.size();
    cols = board[0].size();

    // first row and last row
    for (int i = 0; i < cols; i++) {
      dfs(board, 0, i);
      dfs(board, rows - 1, i);
    }

    // first col and last col
    for (int i = 0; i < rows; i++) {
      dfs(board, i, 0);
      dfs(board, i, cols - 1);
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (board[i][j] == 'I') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};