// @author: Vineet Kumar
// @user: vk-19
// Link:
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  /*  Function to implement Dijkstra
   *   adj: vector of vectors which represents the graph
   *   S: source vertex to start traversing graph with
   *   V: number of vertices
   */
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
// Code here
#define vertex pair<int, int>

    vector<int> d(V, INT_MAX);
    auto comp = [](vertex u, vertex v) { return u.second > v.second; };
    priority_queue<vertex, vector<vertex>, decltype(comp)> Q(comp);
    d[S] = 0;
    Q.push({S, d[S]});
    vector<bool> visited(V, false);

    while (!Q.empty()) {
      vertex curr = Q.top();
      Q.pop();

      int u = curr.first;
      // cout << u << endl;

      if (visited[u]) {
        continue;
      }

      visited[u] = true;
      // int d_u = curr.second;

      for (auto x : adj[u]) {
        int v = x[0];
        // if (visited[v]) {
        //     continue;
        // }
        int w_u_v = x[1];

        if (d[v] > d[u] + w_u_v) {
          d[v] = d[u] + w_u_v;

          Q.push({v, d[v]});
        }
      }
    }

    return d;
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
    int S;
    cin >> S;

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
      cout << res[i] << " ";
    cout << endl;
  }

  return 0;
}

// } Driver Code Ends