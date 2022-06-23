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
class BSTIterator {
    vector<int> vec;
    int ind = 0;
    void inorder(TreeNode* cur) {
        if (!cur) {
            return;
        }
        inorder(cur->left);
        vec.push_back(cur->val);
        inorder(cur->right);
    }

    public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        ind++;
        return vec[ind-1];
    }
    
    bool hasNext() {
        if (ind == vec.size()) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */