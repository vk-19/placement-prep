// @author: Vineet Kumar
// @user: vk-19
// Link: https://leetcode.com/problems/diameter-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int diameter;

  int height(TreeNode *root) {
    if (root == NULL) {
      return -1;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    int temp = left_height + right_height + 2;
    diameter = max(diameter, temp);

    return max(left_height, right_height) + 1;
  }

  int diameterOfBinaryTree(TreeNode *root) {
    diameter = INT_MIN;
    height(root);

    return diameter;
  }
};