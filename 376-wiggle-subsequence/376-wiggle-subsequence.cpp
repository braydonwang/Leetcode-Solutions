class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int dir = 0, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (dir == 0) {
                if (nums[i] > nums[i-1]) {
                    cnt++;
                    dir = -1;
                } else if (nums[i] < nums[i-1]) {
                    cnt++;
                    dir = 1;
                }
            } else if (dir == 1) {
                if (nums[i] > nums[i-1]) {
                    dir = -1;
                    cnt++;
                }
            } else {
                if (nums[i] < nums[i-1]) {
                    dir = 1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};