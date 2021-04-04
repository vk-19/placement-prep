// @author: Vineet Kumar
// @user: vk-19
// Link:

class Solution {
public:
  int count;
  int rows;
  int cols;

  void dfs(vector<vector<char>> &grid, int i, int j) {

    if (grid[i][j] == '0') {
      return;
    }
    // cout << i << " " << j << endl;
    grid[i][j] = '0';

    // left
    if (j - 1 >= 0) {
      dfs(grid, i, j - 1);
    }

    // right
    if (j + 1 < cols) {
      dfs(grid, i, j + 1);
    }

    // bottom
    if (i + 1 < rows) {
      dfs(grid, i + 1, j);
    }

    // top
    if (i - 1 >= 0) {
      dfs(grid, i - 1, j);
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    count = 0;
    rows = grid.size();
    cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == '1') {
          // cout << i << " hello " << j << endl;
          count++;
          dfs(grid, i, j);
        }
      }
    }

    return count;
  }
};