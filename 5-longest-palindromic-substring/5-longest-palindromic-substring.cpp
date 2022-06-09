class Solution {
public:
    int ind = 0;
    int ans = 0;
    void length(string s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--; r++;
        }
        int len = r - l - 1;
        if (len > ans) {
            ans = len;
            ind = l + 1;
        }
    }
    string longestPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            length(s,i,i);
            if (i + 1 < s.length()) {
                length(s,i,i+1);
            }
        }
        return s.substr(ind,ans);
    }
};