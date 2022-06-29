class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> set;
        for (int i = 0; i < nums.size(); i++) {
            long temp = nums[i];
            if (i > k) {
                set.erase(nums[i-k-1]);
            }
            auto num = set.lower_bound(temp-t);
            if (num != set.end() && abs(nums[i] - *num ) <= t) {
                return true;
            }
            set.insert(temp);
        }
        return false;
    }
};