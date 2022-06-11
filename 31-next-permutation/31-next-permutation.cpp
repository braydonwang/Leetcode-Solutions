class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return;
        }
        int ind = n-2;
        while (ind >= 0 && nums[ind] >= nums[ind+1]) {
            ind--;
        }
        if (ind == -1) {
            sort(nums.begin(),nums.end());
            return;
        }
        int num = nums[ind];
        int ind2 = n-1;
        while (nums[ind2] <= num) {
            ind2--;
        }
        swap(nums[ind],nums[ind2]);
        reverse(nums.begin()+ind+1,nums.end());
    }
};