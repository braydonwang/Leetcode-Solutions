class Solution {
public:
    int find(int og, int n, vector<int>& dp) {
        if (n == 1) {
            return 1;
        }
        if (dp[n] != 0) {
            return dp[n];
        }
        if (n != og) {
            dp[n] = n;
        }
        for (int i = 1; i < n; i++) {
            dp[n] = max(dp[n],find(og,i,dp) * find(og,n-i,dp));
        }
        return dp[n];
    }
    int integerBreak(int n) {
        vector<int> dp(n+1);
        return find(n,n,dp);
    }
};