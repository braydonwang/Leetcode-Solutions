class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.length();
        vector<int> vec(n);
        int ctr = 1, inc = 1;
        for (int i = 0; i < n; i++) {
            vec[i] = ctr;
            ctr += inc;
            if (ctr > numRows) {
                ctr = numRows - 1;
                inc = -1;
            } else if (ctr == 0) {
                ctr = 2;
                inc = 1;
            }
        }
        int ind = 1;
        string ret = "";
        while (ind <= numRows) {
            for (int i = 0; i < n; i++){
                if (vec[i] == ind) {
                    ret += s[i];
                }
            }
            ind++;
        }
        return ret;
    }
};