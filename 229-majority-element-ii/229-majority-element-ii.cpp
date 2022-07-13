class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        vector<int> ans;
        int k = nums.size() / 3;
        for (auto const& x: map) {
            if (x.second > k) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};