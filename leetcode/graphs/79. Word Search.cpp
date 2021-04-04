// @author: Vineet Kumar
// @user: vk-19
// Link: https://leetcode.com/problems/word-search/

class Solution {
public:
  int rows, cols;
  bool exist(vector<vector<char>> &board, string word) {
    rows = board.size();
    cols = board[0].size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (dfs(board, i, j, word, 0)) {
          return true;
        }
      }
    }

    return false;
  }

  bool dfs(vector<vector<char>> &board, int i, int j, string &word, int x) {
    if (x == word.length()) {
      return true;
    }

    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[x]) {
      return false;
    }

    board[i][j] = ' ';

    bool found = dfs(board, i - 1, j, word, x + 1) ||
                 dfs(board, i + 1, j, word, x + 1) ||
                 dfs(board, i, j - 1, word, x + 1) ||
                 dfs(board, i, j + 1, word, x + 1);

    board[i][j] = word[x];

    return found;
  }
};