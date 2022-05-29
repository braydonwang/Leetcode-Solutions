/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "x";
        }
        string ret = "(" + to_string(root->val) + ",";
        ret = ret + serialize(root->left) + ",";
        ret = ret + serialize(root->right) + ")";
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "x") {
            return NULL;
        }
        stack<TreeNode*> st;
        int ind = 0;
        while (ind < data.length()) {
            if (data[ind] == '(' || data[ind] == ','){
                ind++;
                continue;
            }
            if (data[ind] == 'x') {
                st.push(NULL);
            } else if (data[ind] == ')') {
                TreeNode* r = st.top(); st.pop();
                TreeNode* l = st.top(); st.pop();
                TreeNode* root = st.top(); st.pop();
                root->left = l;
                root->right = r;
                st.push(root);
            } else {
                TreeNode* newNode = new TreeNode();
                int temp = ind;
                while (data[temp] != ',') {
                   temp++;
                }
                newNode->val = stoi(data.substr(ind,temp-ind));
                st.push(newNode);
                ind = temp;
            }
            ind++;
        }
        return st.top();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));