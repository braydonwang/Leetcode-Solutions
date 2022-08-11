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
    unordered_map<int,int> map;
    int max = 0;
    void find(TreeNode* cur) {
        if (!cur) {
            return;
        }
        map[cur->val]++;
        if (map[cur->val] > max) {
            max = map[cur->val];
        }
        find(cur->left);
        find(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        find(root);
        vector<int> ans;
        for (auto it: map) {
            if (it.second == max) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};