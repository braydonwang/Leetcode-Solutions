class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n-2; j++) {
                int l = j+1, r = n-1;
                while (l < r) {
                    long int sum = (long int)(nums[i] + nums[j]) + (long int)(nums[l] + nums[r]);
                    if (sum == target) {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while (l < r && nums[l+1] == nums[l]) {
                            l++;
                        }
                        l++;
                        while (l < r && nums[r-1] == nums[r]) {
                            r--;
                        }
                        r--;
                    } else if (sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
                while (j+1 < n-2 && nums[j+1] == nums[j]) {
                    j++;
                }
            }
            while (i+1 < n-3 && nums[i+1] == nums[i]){
                i++;
            }
        }
        return ans;
    }
};