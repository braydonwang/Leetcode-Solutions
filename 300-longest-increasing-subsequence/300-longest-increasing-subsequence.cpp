class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        fill_n(dp,nums.size(),1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i],dp[j]+1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};