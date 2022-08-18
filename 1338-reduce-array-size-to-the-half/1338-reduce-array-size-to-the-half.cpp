class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> map;
        for (int num: arr) {
            map[num]++;
        }
        vector<int> v;
        for (auto it: map) {
            v.push_back(it.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int ans = 0, sum = 0;
        for (int num: v) {
            sum += num;
            ans++;
            if (sum >= arr.size()/2) {
                return ans;
            }
        }
        return ans;
    }
};