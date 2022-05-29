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
    vector<vector<int>> vec;
    void level(TreeNode* node, int num) {
        if (!node) {
            return;
        }
        if (vec.size() == num) {
            vec.push_back(vector<int>());
        }
        vec[num].push_back(node->val);
        level(node->left,num+1);
        level(node->right,num+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        level(root,0);
        return vec;
    }
};