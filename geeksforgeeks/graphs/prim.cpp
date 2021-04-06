// @author: Vineet Kumar
// @user: vk-19
// Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  // Function to construct and print MST for
  // a graph represented using adjacency
  // list representation, with V vertices.
  int spanningTree(int V, vector<vector<int>> adj[]) {
    // code here
    vector<int> key(V, INT_MAX);
    // vector<int> parent(V);

#define vertex pair<int, int>

    auto comp = [](vertex u, vertex v) { return u.second > v.second; };

    priority_queue<vertex, vector<vertex>, decltype(comp)> Q(comp);

    key[0] = 0;

    Q.push({0, key[0]});

    vector<bool> visited(V, false);

    while (!Q.empty()) {
      int u = Q.top().first;
      Q.pop();
      if (visited[u])
        continue;
      visited[u] = true;
      // cout << u << " " << key[u] << endl;
      for (auto &x : adj[u]) {
        int v = x[0];
        int w_u_v = x[1];

        if (!visited[v] && key[v] > w_u_v) {
          key[v] = w_u_v;

          Q.push({v, key[v]});
        }
      }
    }

    // int cost = 0;
    return accumulate(key.begin(), key.end(), 0);
    // return cost;
  }
};

// { Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E) {
      int u, v, w;
      cin >> u >> v >> w;
      vector<int> t1, t2;
      t1.push_back(v);
      t1.push_back(w);
      adj[u].push_back(t1);
      t2.push_back(u);
      t2.push_back(w);
      adj[v].push_back(t2);
    }

    Solution obj;
    cout << obj.spanningTree(V, adj) << "\n";
  }

  return 0;
}

// } Driver Code Ends