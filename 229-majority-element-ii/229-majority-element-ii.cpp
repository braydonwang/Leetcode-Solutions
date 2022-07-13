class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 1;
        for (int num: nums) {
            if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            } else if (cnt1 == 0) {
                num1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                num2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;
        for (int num: nums) {
            if (num == num1) {
                cnt1++;
            } else if (num == num2) {
                cnt2++;
            }
        }
        vector<int> ans;
        int k = nums.size() / 3;
        if (cnt1 > k) {
            ans.push_back(num1);
        }
        if (cnt2 > k) {
            ans.push_back(num2);
        }
        return ans;
    }
};