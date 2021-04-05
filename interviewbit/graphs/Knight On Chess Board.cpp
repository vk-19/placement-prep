// @author: Vineet Kumar
// @user: vk-19
// Link: https://www.interviewbit.com/problems/knight-on-chess-board/

struct cell {
  int x, y, dist;
};

bool isValid(int x, int y, int A, int B) {
  if (x < 0 || x >= A || y < 0 || y >= B)
    return false;

  return true;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
  cell start = {C - 1, D - 1, 0};
  queue<cell> q;
  q.push(start);

  int dx[] = {2, 1, -1, -2, 2, 1, -1, -2};
  int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

  vector<vector<bool>> visited(A, vector<bool>(B, false));
  visited[C - 1][D - 1] = true;

  while (!q.empty()) {
    cell curr = q.front();
    q.pop();

    if (curr.x == E - 1 && curr.y == F - 1) {
      return curr.dist;
    }

    for (int i = 0; i < 8; i++) {
      int x = curr.x + dx[i];
      int y = curr.y + dy[i];

      if (isValid(x, y, A, B) && !visited[x][y]) {
        int dist = curr.dist + 1;
        q.push({x, y, dist});
        visited[x][y] = true;
      }
    }
  }

  return -1;
}
