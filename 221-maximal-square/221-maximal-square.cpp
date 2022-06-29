class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> dp(matrix[0].size());
        int ans = 0, pre = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int temp = dp[j];
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp[j] = matrix[i][j] - '0';
                } else if (matrix[i][j] == '1') {
                    dp[j] = min(pre,min(dp[j],dp[j-1])) + 1;
                }
                ans = max(ans,dp[j]);
                pre = temp;
            }
        }
        return ans*ans;
    }
};