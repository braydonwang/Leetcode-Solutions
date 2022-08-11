class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz-1; i++) {
            nums.push_back(nums[i]);
        }
        stack<int> st;
        vector<int> ans(sz,-1);
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                if (st.top() < sz) {
                    ans[st.top()] = nums[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};