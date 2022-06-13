class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j <= i+nums[i] && j < n; j++) {
                if (dp[j] != INT_MAX) {
                    dp[i] = min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[0];
    }
};