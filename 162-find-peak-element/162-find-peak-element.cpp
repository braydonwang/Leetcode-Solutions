class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if ((mid-1 < 0 || nums[mid] > nums[mid-1]) && (mid + 1 >= nums.size() || nums[mid] > nums[mid+1])) {
                return mid;
            } else if (mid-1 >= 0 && nums[mid] < nums[mid-1]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return 0;
    }
};