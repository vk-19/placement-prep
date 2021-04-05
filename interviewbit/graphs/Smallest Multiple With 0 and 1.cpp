// @author: Vineet Kumar
// @user: vk-19
// Link: https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

string Solution::multiple(int A) {
  if (A == 1) {
    return "1";
  }

  vector<string> dp(A);
  // dp[i] stores the smallest number such that the remainder is i
  // remainder can go from 0 to n-1
  // we need to find dp[0]
  dp[1] = "1";
  queue<int> q;
  q.push(1);

  while (!q.empty()) {
    int R = q.front();
    q.pop();

    if (R == 0) {
      return dp[0];
    }

    for (int digit : {0, 1}) {
      int newR = (10 * R + digit) % A;

      if (dp[newR].empty()) {
        q.push(newR);
        dp[newR] = dp[R] + char('0' + digit);
      }
    }
  }

  return "-1";
}
