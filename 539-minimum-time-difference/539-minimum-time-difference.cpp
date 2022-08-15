class Solution {
public:
    static bool compare(string& s1, string& s2) {
        int a = stoi(s1.substr(0,2)), b = stoi(s1.substr(3,2)), c = stoi(s2.substr(0,2)), d = stoi(s2.substr(3,2));
        if (a == c) {
            return b < d;
        }
        return a < c;
    }
    int diff(string& s1, string& s2) {
        int a = stoi(s1.substr(0,2)), b = stoi(s1.substr(3,2)), c = stoi(s2.substr(0,2)), d = stoi(s2.substr(3,2));
        return (c-a)*60 + (d-b);
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end(),compare);
        int ans = INT_MAX;
        for (int i = 1; i < timePoints.size(); i++) {
            ans = min(ans,diff(timePoints[i-1],timePoints[i]));
        }
        ans = min(ans,24*60-diff(timePoints[0],timePoints[timePoints.size()-1]));
        return ans;
    }
};