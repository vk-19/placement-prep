// @author: Vineet Kumar
// @user: vk-19
// Link: https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (node == NULL)
      return NULL;

    Node *clone = new Node(node->val);

    queue<Node *> q;
    q.push(node);
    unordered_map<Node *, Node *> mp;
    mp[node] = clone;

    while (!q.empty()) {
      Node *curr = q.front();
      q.pop();

      for (auto &neighbor : curr->neighbors) {
        if (mp.find(neighbor) == mp.end()) {
          Node *cloneNeighbor = new Node(neighbor->val);
          mp[neighbor] = cloneNeighbor;
          q.push(neighbor);
        }

        mp[curr]->neighbors.push_back(mp[neighbor]);
      }
    }

    return clone;
  }
};