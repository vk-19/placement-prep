class Solution {
public:
  vector<vector<string>> ans;
  unordered_map<string, vector<string>> adj;
  unordered_map<string, int> depth;

  void dfs(string beginWord, string endWord, vector<string> &path) {
    cout << beginWord << endl;
    path.push_back(beginWord);

    if (beginWord == endWord) {
      ans.push_back(path);
      path.pop_back();
      return;
    }

    for (auto word : adj[beginWord]) {
      dfs(word, endWord, path);
    }

    path.pop_back();
  }

  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {

    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    //         for (auto word : wordList) {
    //             wordSet.insert(word);
    //         }

    queue<string> q;
    q.push(beginWord);
    depth[beginWord] = 0;

    while (!q.empty()) {
      // cout << "hello" << endl;
      //             int level_size = q.size();

      //             while (level_size--) {
      string curr = q.front();
      q.pop();

      string temp = curr;

      for (int i = 0; i < curr.length(); i++) {
        // cout << "rock" << endl;
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (curr[i] != ch) {
            temp[i] = ch;

            if (wordSet.count(temp) > 0) {
              if (depth.count(temp) == 0) {
                q.push(temp);
                adj[curr].push_back(temp);
                depth[temp] = depth[curr] + 1;
              } else if (depth[temp] == depth[curr] + 1) {
                adj[curr].push_back(temp);
              }
            }

            //                             if (depth[temp] == depth[curr] + 1) {
            //                                 adj[curr].push_back(temp);
            //                                 continue;
            //                             }

            //                             if (temp == beginWord || depth[temp]
            //                             > 0) {
            //                                 continue;
            //                             }

            //                             if (wordSet.find(temp) !=
            //                             wordSet.end()) {
            //                                 // cout << "t: " << temp << endl;
            //                                 q.push(temp);
            //                                 adj[curr].push_back(temp);
            //                                 depth[temp] = depth[curr] + 1;

            //                                 // wordSet.erase(temp);
            //                             }
          }
        }

        temp[i] = curr[i];
      }
      // }
    }

    vector<string> path;
    // cout << "heell " << beginWord << endl;
    dfs(beginWord, endWord, path);

    return ans;
  }
};