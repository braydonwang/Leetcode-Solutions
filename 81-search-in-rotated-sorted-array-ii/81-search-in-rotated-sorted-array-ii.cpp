class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi) {
            while (lo < hi && nums[lo] == nums[lo+1]) {
                lo++;
            }
            while (lo < hi && nums[hi] == nums[hi-1]) {
                hi--;
            }
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[lo] <= nums[mid]) {
                if (nums[mid] < target || nums[lo] > target) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else {
                if (nums[mid] > target || nums[hi] < target) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return false;
    }
};