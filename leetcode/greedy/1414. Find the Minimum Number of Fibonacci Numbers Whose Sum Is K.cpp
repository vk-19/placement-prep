// @author: Vineet Kumar
// @user: vk-19
// Link:
// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

class Solution {
public:
  int findMinFibonacciNumbers(int k) {
    vector<int> fib = {1, 1};
    int a = 1;
    int b = 1;
    int c = 2;

    while (c <= k) {
      fib.push_back(c);
      a = b;
      b = c;
      c = a + b;
    }

    int count = 0;
    // cout << fib.size() << endl;

    //         for (int i = fib.size() - 1; i >= 0; i--) {
    //             // cout << "hello";
    //             cout << k << " " << fib[i] << endl;
    //             if (k >= fib[i]) {
    //                 int temp = k / fib[i];
    //                 count += temp;
    //                 // count++;
    //                 k -= temp * fib[i];
    //                 // k -= fib[i];

    //                 if (k == 0) {
    //                     break;
    //                 }
    //             }
    //         }

    while (k > 0) {
      count++;
      k -= fib.back();

      while (fib.size() > 0 && k < fib.back()) {
        fib.pop_back();
      }
    }

    return count;
  }
};