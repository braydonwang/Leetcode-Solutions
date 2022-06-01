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
    bool check(TreeNode* root, TreeNode* p) {
        if (!root) {
            return false;
        } else if (root->val == p->val) {
            return true;
        } else {
            return check(root->left,p) || check(root->right,p);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool lp = check(root->left,p);
        bool lq = check(root->left,q);
        bool rp = check(root->right,p);
        bool rq = check(root->right,q);
        if ((lp && rq) || (lq && rp)) {
            return root;
        } else if (root->val == p->val || root->val == q->val) {
            return root;
        } else if (lp && lq) {
            return lowestCommonAncestor(root->left,p,q);
        } else {
            return lowestCommonAncestor(root->right,p,q);
        }
    }
};