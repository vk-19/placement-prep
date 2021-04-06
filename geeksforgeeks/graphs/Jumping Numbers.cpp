// @author: Vineet Kumar
// @user: vk-19
// Link: https://practice.geeksforgeeks.org/problems/jumping-numbers3805/1#

class Solution {
public:
  long long ans = -1;
  long long jumpingNums(long long X) {
    // code here

    for (int i = 1; i <= 9 && i <= X; i++) {
      bfs(i, X);
    }

    return ans;
  }

  void bfs(int i, int X) {
    queue<long long> q;
    q.push(i);

    while (!q.empty()) {
      int temp = q.front();
      q.pop();

      if (temp <= X) {
        if (temp > ans) {
          ans = temp;
        }

        int last_digit = temp % 10;

        if (last_digit == 0) {
          q.push(temp * 10 + 1);
        } else if (last_digit == 9) {
          q.push(temp * 10 + 8);
        } else {
          q.push(temp * 10 + (last_digit - 1));
          q.push(temp * 10 + (last_digit + 1));
        }
      }
    }
  }
};