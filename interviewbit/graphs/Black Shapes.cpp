// @author: Vineet Kumar
// @user: vk-19
// Link: https://www.interviewbit.com/problems/black-shapes/#

void dfs(vector<string> &A, int i, int j) {
  if (i < 0 || i >= A.size() || j < 0 || j >= A[0].length() || A[i][j] == 'O') {
    return;
  }

  A[i][j] = 'O';
  dfs(A, i - 1, j);
  dfs(A, i + 1, j);
  dfs(A, i, j - 1);
  dfs(A, i, j + 1);
}

int Solution::black(vector<string> &A) {
  int rows = A.size();
  int cols = A[0].length();

  int ans = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (A[i][j] == 'X') {
        ans++;
        dfs(A, i, j);
      }
    }
  }

  return ans;
}
