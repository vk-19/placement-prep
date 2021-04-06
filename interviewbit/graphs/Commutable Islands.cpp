// @author: Vineet Kumar
// @user: vk-19
// Link: https://www.interviewbit.com/problems/commutable-islands/

struct Node {
  int data, rank;
  Node *parent;

  Node(int data) : data(data), rank(0), parent(this){};
};

unordered_map<int, Node *> mp;

void makeSet(int u) {
  Node *node = new Node(u);
  mp[u] = node;
}

Node *findSet(Node *node) {
  if (node->parent == node)
    return node;

  node->parent = findSet(node->parent);
  return node->parent;
}

Node *findSet(int u) { return findSet(mp[u]); }

void unionSet(int u, int v) {
  Node *set1 = findSet(mp[u]);
  Node *set2 = findSet(mp[v]);

  if (set1 == set2)
    return;

  if (set1->rank == set2->rank) {
    set2->parent = set1;
    set1->rank += 1;
  } else if (set1->rank > set2->rank) {
    set2->parent = set1;
  } else {
    set1->parent = set2;
  }
}

int Solution::solve(int A, vector<vector<int>> &B) {

  int cost = 0;

  sort(B.begin(), B.end(),
       [](vector<int> e1, vector<int> e2) { return e1.back() < e2.back(); });

  // makeSet
  for (int u = 1; u <= A; u++) {
    makeSet(u);
  }

  for (auto &e : B) {
    int u = e[0];
    int v = e[1];
    int w = e[2];

    if (findSet(u) != findSet(v)) {
      cost += w;
      unionSet(u, v);
    }
  }

  return cost;
}
