class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> map;
        int ans = 0;
        map[nums[0]]++;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                if (k == 0) {
                    if (map.find(nums[i]) != map.end() && map[nums[i]] == 1) {
                        ans++;
                    }
                }
                map[nums[i]]++;
                continue;
            }
            if (map.find(nums[i]-k) != map.end()) {
                ans++;
            }
            map[nums[i]]++;
        }
        return ans;
    }
};