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
    int ans = INT_MAX;
    TreeNode* prev;
    void get(TreeNode* root) {
        if (!root) {
            return;
        }
        get(root->left);
        if (prev) {
            ans = min(ans,root->val-prev->val);
        }
        prev = root;
        get(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        get(root);
        return ans;
    }
};