class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX, ret = 0;
        int a = 0, b = 1, c = nums.size()-1;
        while (a < nums.size()-2) {
            while (b < c) {
                int sum = nums[a] + nums[b] + nums[c];
                if (abs(target-sum) < ans) {
                    ans = abs(target-sum);
                    ret = sum;
                }
                if (sum > target) {
                    c--;
                } else {
                    b++;
                }
            }
            a++;
            b = a + 1;
            c = nums.size()-1;
        }
        return ret;
    }
};