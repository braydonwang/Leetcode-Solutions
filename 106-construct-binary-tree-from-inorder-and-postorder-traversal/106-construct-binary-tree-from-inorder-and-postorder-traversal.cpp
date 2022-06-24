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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root;
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1, root);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2, TreeNode* cur) {
        if (l1 > r1 || l2 > r2) {
            return NULL;
        }
        int ind1 = l1, ind2 = l2;
        while (ind1 < r1 && inorder[ind1] != postorder[r2]) {
            ind1++;
        }
        cur = new TreeNode(inorder[ind1]);
        cur->left = build(inorder,postorder,l1,ind1-1,l2,l2+ind1-l1-1,cur->left);
        cur->right = build(inorder,postorder,ind1+1,r1,l2+ind1-l1,r2-1,cur->right);
        return cur;
    }
};