class Solution {
public:
    static bool compare(string& s1, string& s2) {
        return s1.length() > s2.length();
    }
    bool isSub(string s, string str) {
        int ind = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == s[ind]) {
                ind++;
                if (ind == s.length()) {
                    return true;
                }
            }
        }
        return false;
    }
    bool check(vector<string>& strs, string s, int ind) {
        for (int i = 0; i <= ind; i++) {
            if (isSub(s,strs[i])) {
                return false;
            }
        }
        return true;
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),compare);
        unordered_map<string,int> freq;
        for (string s: strs) {
            freq[s]++;
        }
        for (int i = 0; i < strs.size(); i++) {
            if (freq[strs[i]] == 1 && check(strs,strs[i],i-1)) {
                return strs[i].length();
            }
        }
        return -1;
    }
};