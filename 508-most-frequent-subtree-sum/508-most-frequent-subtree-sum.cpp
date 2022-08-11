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
    int max = 0;
    unordered_map<int,int> map;
    int find(TreeNode* cur) {
        if (!cur) {
            return 0;
        }
        int temp = cur->val + find(cur->left) + find(cur->right);
        map[temp]++;
        if (map[temp] > max) {
            max = map[temp];   
        }
        return temp;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
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