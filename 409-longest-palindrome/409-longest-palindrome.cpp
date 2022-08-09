class Solution {
public:
    int longestPalindrome(string s) {
        bool odd = false;
        unordered_map<char,int> map;
        for (char c: s) {
            map[c]++;
        }
        int ans = 0;
        for (auto it: map) {
            if (it.second % 2 != 0) {
                odd = true;
                ans += it.second - 1;
            } else {
                ans += it.second;
            }
        }
        if (odd) {
            ans++;
        }
        return ans;
    }
};