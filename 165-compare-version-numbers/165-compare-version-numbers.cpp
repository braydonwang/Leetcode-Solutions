class Solution {
public:
    vector<string> split(string s) {
        vector<string> ret;
        int ind = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') {
                if (ind != -1) {
                    ret.push_back(s.substr(ind,i-ind));
                    ind = -1;
                }
            } else {
                if (ind == -1) {
                    ind = i;
                }
            }
        }
        if (ind != -1) {
            ret.push_back(s.substr(ind,s.length()-ind));
        }
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1);
        vector<string> v2 = split(version2);
        int len = max(v1.size(),v2.size());
        int num1 = 0, num2 = 0;
        for (int i = 0; i < len; i++) {
            if (i < v1.size()) {
                num1 = stoi(v1[i]);
            } else {
                num1 = 0;
            }
            if (i < v2.size()) {
                num2 = stoi(v2[i]);
            } else {
                num2 = 0;
            }
            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
        }
        return 0;
    }
};