class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> q;
        vector<string> ans(score.size());
        for (int i = 0; i < score.size(); i++) {
            q.push({score[i],i});
        }
        int count = 1;
        while (!q.empty()) {
            pair<int,int> p = q.top(); q.pop();
            if (count == 1) {
                ans[p.second] = "Gold Medal";
            } else if (count == 2) {
                ans[p.second] = "Silver Medal";
            } else if (count == 3) {
                ans[p.second] = "Bronze Medal";
            } else {
                ans[p.second] = to_string(count);
            }
            count++;
        }
        return ans;
    }
};