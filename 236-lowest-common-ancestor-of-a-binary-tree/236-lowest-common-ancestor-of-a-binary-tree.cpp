/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool has(TreeNode* root, int val) {
        if (!root) {
            return false;
        }
        if (root->val == val) {
            return true;
        }
        return has(root->left,val) || has(root->right,val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        bool fst = has(root->left,p->val), snd = has(root->left,q->val);
        if (fst && snd) {
            return lowestCommonAncestor(root->left,p,q);
        } else if (!fst && !snd) {
            return lowestCommonAncestor(root->right,p,q);
        } else {
            return root;
        }
    }
};