class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int l = newInterval[0], r = newInterval[1];
        int start = l, end = r;
        for (int i = 0; i < intervals.size(); i++) {
            int fst = intervals[i][0], sec = intervals[i][1];
            if (fst >= l && sec <= r) {
                continue;
            } else if (sec < l) {
                ret.push_back(intervals[i]);
            } else if (fst <= l && sec >= l) {
                start = fst;
                if (fst <= r && sec >= r) {
                 end = sec;
                }
            } else if (fst <= r && sec >= r) {
                end = sec;
            } else {
                if (start == -2) {
                    ret.push_back(intervals[i]);
                    continue;
                }
                ret.push_back({start,end});
                start = -2;
                ret.push_back(intervals[i]);
            }
        }
        if (start != -2) {
            ret.push_back({start,end});
        }
        return ret;
    }
};