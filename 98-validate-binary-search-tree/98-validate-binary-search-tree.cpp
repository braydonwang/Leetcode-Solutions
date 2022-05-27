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
typedef long long int lli;
class Solution {
public:
    bool isValidBST(TreeNode* root, lli left=(lli)INT_MIN-5, lli right=(lli)INT_MAX+5) {
        if (!root) {
            return true;
        }
        if (left >= root->val || right <= root->val) {
            return false;
        }
        return isValidBST(root->left,left,root->val) && isValidBST(root->right,root->val,right);
    }
};