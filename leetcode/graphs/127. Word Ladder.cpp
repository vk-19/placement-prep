// @author: Vineet Kumar
// @user: vk-19
// Link: https://leetcode.com/problems/word-ladder/

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> wordSet;
    bool endWordPresent = false;
    for (auto word : wordList) {
      wordSet.insert(word);
      if (word == endWord) {
        endWordPresent = true;
      }
    }

    if (!endWordPresent) {
      return 0;
    }

    int depth = 0;

    queue<string> q;
    q.push(beginWord);

    while (!q.empty()) {
      depth += 1;
      int lsize = q.size();

      while (lsize--) {
        string curr = q.front();
        q.pop();

        string temp = curr;

        for (int i = 0; i < curr.length(); i++) {
          for (char ch = 'a'; ch <= 'z'; ch++) {
            if (curr[i] != ch) {
              temp[i] = ch;

              if (temp == endWord) {
                return depth + 1;
              }

              if (wordSet.find(temp) != wordSet.end()) {
                q.push(temp);
                wordSet.erase(temp);
              }
            }
          }

          temp[i] = curr[i];
        }
      }
    }

    return 0;
  }
};