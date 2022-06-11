class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        vector<int> ans = {-1,-1};
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                int i = mid;
                while (i >= 0 && nums[i] == target) {
                    i--;
                }
                int j = mid;
                while (j < nums.size() && nums[j] == target) {
                    j++;
                }
                ans[0] = i+1; ans[1] = j-1;
                break;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};