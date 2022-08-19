class Solution {
public:
    vector<int> og;
    Solution(vector<int>& nums) {
        og = nums;
    }
    
    vector<int> reset() {
        return og;
    }
    
    vector<int> shuffle() {
        vector<int> ans(og);
        for (int i = 0; i < og.size(); i++) {
            int ind = rand() % og.size();
            swap(ans[i],ans[ind]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */