class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i]) != set.end()) {
                set.erase(nums[i]);
                int l = nums[i]-1, r = nums[i]+1;
                while (set.find(l) != set.end()) {
                    set.erase(l); l--;
                }
                while (set.find(r) != set.end()) {
                    set.erase(r); r++;
                }
                ans = max(ans,r-l-1);
            }
        }
        return ans;
    }
};