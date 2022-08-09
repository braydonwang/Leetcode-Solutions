class Solution {
public:
    vector<string> v{"qwertyuiop","asdfghjkl","zxcvbnm"};
    int row(char c) {
        c = tolower(c);
        for (int i = 0; i < 3; i++) {
            if (find(v[i].begin(),v[i].end(),c) != v[i].end()) {
                return i;
            }
        }
        return 2;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for (string str: words) {
            int num = row(str[0]);
            bool good = true;
            for (int i = 1; i < str.size(); i++) {
                if (row(str[i]) != num) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans.push_back(str);
            }
        }
        return ans;
    }
};