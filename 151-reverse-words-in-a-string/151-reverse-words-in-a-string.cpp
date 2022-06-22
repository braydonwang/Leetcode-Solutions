class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;
        int l = -1, r = 0;
        while (r < s.length()) {
            if (s[r] != ' ') {
                if (l == -1) {
                    l = r;
                }
            } else {
                if (l != -1) {
                    vec.push_back(s.substr(l,r-l));
                    l = -1;
                }
            }
            r++;
        }
        if (l != -1) {
            vec.push_back(s.substr(l,r-l));
        }
        string ans = "";
        for (int i = vec.size()-1; i >= 0; i--) {
            if (i == 0) {
                ans += vec[i];
            } else {
                ans += vec[i] + " ";
            }
        }
        return ans;
    }
};