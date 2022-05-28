class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for (auto num: map) {
            pq.push(make_pair(num.second,num.first));   
        }
        vector<int> res;
        while (k) {
            pair<int,int> p = pq.top();
            pq.pop();
            res.push_back(p.second);
            k--;
        }
        return res;
    }
};