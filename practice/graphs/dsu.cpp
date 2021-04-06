#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Node {
  int data;
  int rank;
  Node *parent;

  Node(int data) : data(data), rank(0), parent(this) {}
};

class DisjoinSet {

  unordered_map<int, Node *> mp;

public:
  void makeSet(int data) {
    Node *p = new Node(data);
    mp[data] = p;
  }

  Node *findSet(Node *node) {
    if (node->parent == node) {
      return node;
    }

    node->parent = findSet(node->parent);
    // node->parent = parent;
    return node->parent;
  }

  void unionSets(int set1, int set2) {
    Node *s1 = findSet(mp[set1]);
    Node *s2 = findSet(mp[set2]);

    if (s1 == s2) {
      return;
    }

    if (s1->rank == s2->rank) {
      s2->parent = s1;
    } else if (s1->rank > s2->rank) {
      s2->parent = s1;
    } else {
      s1->parent = s2;
    }
  }
};
