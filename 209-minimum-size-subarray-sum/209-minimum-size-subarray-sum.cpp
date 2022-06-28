class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, ans = INT_MAX, sum = nums[0];
        while (l <= r && r < nums.size()) {
            if (sum >= target) {
                ans = min(ans,r - l + 1);
                sum -= nums[l];
                l++;
            } else {
                r++;
                if (r == nums.size()) {
                    break;
                }
                sum += nums[r];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};