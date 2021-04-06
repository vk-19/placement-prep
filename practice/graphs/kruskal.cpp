#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct edge {
  int u, v, w;
};

struct Node {
  int data, rank;
  Node *parent;
  Node(int data) : data(data), rank(0), parent(this) {}
};

class Solution {

public:
  unordered_map<int, Node *> mp;
  void kruskal(int V, vector<vector<pair<int, int>>> adj) {
    vector<edge> edges;

    for (int u = 0; u < adj.size(); u++) {
      for (auto &x : adj[u]) {
        int v = x.first;
        int w = x.second;

        edges.push_back({u, v, w});
      }
    }

    sort(edges.begin(), edges.end(),
         [](edge e1, edge e2) { return e1.w < e2.w; });

    for (int u = 0; u < V; u++) {
      makeSet(u);
    }

    // vector<bool> included(edges.size(), false);
    vector<edge> A;

    for (auto &e : edges) {
      if (findSet(e.u) != findSet(e.v)) {
        A.push_back(e);
        unionSets(e.u, e.v);
      }
    }
  }

  void makeSet(int v) {
    Node *node = new Node(v);
    mp[v] = node;
  }

  Node *findSet(int u) { return findSet(mp[u]); }

  Node *findSet(Node *node) {
    if (node->parent == node) {
      return node;
    }

    node->parent = findSet(node->parent);
    return node->parent;
  }

  void unionSets(int u, int v) {
    Node *set1 = findSet(mp[u]);
    Node *set2 = findSet(mp[v]);

    if (set1 == set2) {
      return;
    }

    if (set1->rank == set2->rank) {
      set2->parent = set1;
      set1->rank += 1;
    } else if (set1->rank > set2->rank) {
      set2->parent = set1;
    } else {
      set1->parent = set2;
    }
  }
};