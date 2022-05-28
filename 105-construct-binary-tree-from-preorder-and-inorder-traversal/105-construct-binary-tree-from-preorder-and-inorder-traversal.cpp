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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root = 0;
        return build(preorder, inorder, root, 0, inorder.size() - 1);
    }
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int& root, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int index = 0;
        for (int i = l; i <= r; i++) {
            if (inorder[i] == preorder[root]) {
                index = i;
                break;
            }
        }
        TreeNode *tree = new TreeNode(inorder[index]);
        root++;
        tree->left = build(preorder, inorder, root, l, index-1);
        tree->right = build(preorder, inorder, root, index+1, r);
        return tree;
    }
};