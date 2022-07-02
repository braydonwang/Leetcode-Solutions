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
    int height(TreeNode* cur) {
        if (cur == NULL) {
            return 0;
        }
        return 1 + height(cur->left);
    }
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int hl = height(root->left), hr = height(root->right);
        if (hl > hr) {
            return countNodes(root->left) + (1 << hr);
        } else {
            return countNodes(root->right) + (1 << hl);
        }
    }
};