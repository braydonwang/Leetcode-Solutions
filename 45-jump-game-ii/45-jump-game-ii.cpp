class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0, cur = 0, mx = 0, ans = 0;
        while (i < n-1) {
            mx = max(mx,i+nums[i]);
            if (i == cur) {
                ans++;
                cur = mx;
            }
            i++;
        }
        return ans;
    }
};