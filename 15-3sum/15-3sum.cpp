class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() <= 2) {
            return ret;
        }
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int lo = i + 1, hi = nums.size()-1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] == -nums[i]) {
                    ret.push_back({nums[i],nums[lo],nums[hi]});
                    while (lo < hi && nums[lo+1] == nums[lo]) {
                        lo++;
                    }
                    while (lo < hi && nums[hi-1] == nums[hi]) {
                        hi--;
                    }
                    lo++; hi--;
                } else if (nums[lo] + nums[hi] < -nums[i]) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
        return ret;
    }
};