class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combine(0,temp,candidates,target,ans);
        return ans;
    }
    void combine(int ind, vector<int> vec, vector<int>& candidates, int target, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(vec);
            return;
        } else if (target < 0) {
            return;
        }
        if (ind == candidates.size()) {
            return;
        }
        combine(ind+1,vec,candidates,target,ans);
        vec.push_back(candidates[ind]);
        combine(ind,vec,candidates,target-candidates[ind],ans);
    }
};