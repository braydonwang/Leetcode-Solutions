/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* cur) {
        if (!cur) {
            return 0;
        }
        return max(depth(cur->left),depth(cur->right)) + 1;
    }
    int findBottomLeftValue(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val;
        }
        int l = depth(root->left), r = depth(root->right);
        if (r > l) {
            return findBottomLeftValue(root->right);
        } else {
            return findBottomLeftValue(root->left);
        }
    }
};