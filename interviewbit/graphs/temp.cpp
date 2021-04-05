// @author: Vineet Kumar
// @user: vk-19
// Link: https://www.interviewbit.com/problems/knight-on-chess-board/

#include <bits/stdc++.h>
using namespace std;

void print_board(vector<vector<bool>> &board) {
  int rows = board.size();
  int cols = board[0].size();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
}

void dfs(vector<vector<bool>> &board, int i, int j, int rows, int cols, int E,
         int F, int moves, int &min_moves) {
  if (i == E && j == F && moves < min_moves) {
    min_moves = moves;
    cout << moves << endl;
    print_board(board);
    return;
  }
  //   cout << i << " " << j << endl;
  if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j]) {
    return;
  }

  board[i][j] = true;

  dfs(board, i - 2, j - 1, rows, cols, E, F, moves + 1, min_moves);
  dfs(board, i - 2, j + 1, rows, cols, E, F, moves + 1, min_moves);
  dfs(board, i - 1, j + 2, rows, cols, E, F, moves + 1, min_moves);
  dfs(board, i + 1, j + 2, rows, cols, E, F, moves + 1, min_moves);
  dfs(board, i + 2, j + 1, rows, cols, E, F, moves + 1, min_moves);
  dfs(board, i + 2, j - 1, rows, cols, E, F, moves + 1, min_moves);
  dfs(board, i + 1, j - 2, rows, cols, E, F, moves + 1, min_moves);
  dfs(board, i - 1, j - 2, rows, cols, E, F, moves + 1, min_moves);

  board[i][j] = false;
}

int knight(int A, int B, int C, int D, int E, int F) {
  int min_moves = INT_MAX;
  vector<vector<bool>> board(A, vector<bool>(B, false));
  dfs(board, C - 1, D - 1, A, B, E - 1, F - 1, 0, min_moves);

  if (min_moves == INT_MAX) {
    return -1;
  }

  return min_moves;
}

int main() { cout << knight(8, 8, 1, 1, 8, 8); }

// A : 8
// B : 8
// C : 1
// D : 1
// E : 8
// F : 8
