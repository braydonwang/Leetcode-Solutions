class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int can = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (i + nums[i] >= can) {
                can = i;
            }
        }
        return can == 0 ? true : false;
    }
};