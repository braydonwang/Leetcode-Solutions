class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> pre(matrix[0].size());
        vector<int> dp(matrix[0].size());
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp[j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    dp[j] = min(dp[j-1],min(pre[j],pre[j-1])) + 1;
                }
                ans = max(ans,dp[j]);
            }
            pre = dp;
        }
        return ans*ans;
    }
};