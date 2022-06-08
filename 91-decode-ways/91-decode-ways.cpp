class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,0);
        int f = s[0] - '0';
        if (f >= 1 && f <= 9) {
            dp[0] = 1;
        }
        if (n == 1) {
            return dp[0];
        }
        int t = s[1] - '0', fs = (s[0]-'0') * 10 + s[1] - '0';
        if (t >= 1 && t <= 9) {
            dp[1] = dp[0];
        }
        if (fs >= 10 && fs <= 26) {
            dp[1] += 1;
        }
        for (int i = 2; i < n; i++) {
            f = s[i] - '0'; fs = (s[i-1] - '0') * 10 + s[i] - '0';
            if (f >= 1 && f <= 9) {
                dp[i] = dp[i-1];
            }
            if (fs >= 10 && fs <= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n-1];
    }
};