bool comp(vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
}
    
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int end = intervals[0][1];
        int ans = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                ans++;
            }
        }
        return intervals.size()-ans;
    }
};