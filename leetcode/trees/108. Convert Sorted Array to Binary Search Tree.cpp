// @author: Vineet Kumar
// @user: vk-19
// Link:
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.size() == 0) {
      return nullptr;
    }
    return constructTree(nums, 0, nums.size() - 1);
  }

  TreeNode *constructTree(vector<int> &nums, int low, int high) {
    if (low > high) {
      return nullptr;
    }
    int mid = low + (high - low) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = constructTree(nums, low, mid - 1);
    root->right = constructTree(nums, mid + 1, high);

    return root;
  }
};