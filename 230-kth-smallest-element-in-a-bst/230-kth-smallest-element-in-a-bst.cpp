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
    vector<int> vec;
    void traverse(TreeNode* node) {
        if (node){
            traverse(node->left);
            vec.push_back(node->val);
            traverse(node->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root);
        return vec[k-1];
    }
};