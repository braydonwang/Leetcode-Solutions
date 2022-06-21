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
    int sum = 0;
    int tilt(TreeNode* cur) {
        if (!cur) {
            return 0;
        }
        int l = tilt(cur->left);
        int r = tilt(cur->right);
        sum += abs(r - l);
        return l + r + cur->val;
    }
    int findTilt(TreeNode* root) {
        tilt(root);
        return sum;
    }
};