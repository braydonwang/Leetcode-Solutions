class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n);
        return word(0, s, wordDict, dp) == 1 ? true : false;
    }
    int word(int ind, string s, vector<string>& wordDict, vector<int>& dp) {
        if (ind == s.length()) {
            return 1;
        }
        if (dp[ind] != 0) {
            return dp[ind];
        }
        for (int i = ind; i < s.length(); i++) {
            string sub = s.substr(ind,i-ind+1);
            if (find(wordDict.begin(),wordDict.end(),sub) != wordDict.end()) {
                if (word(i+1,s,wordDict,dp) == 1) {
                    return dp[ind] = 1;
                }
            }
        }
        return dp[ind] = 2;
    }
};