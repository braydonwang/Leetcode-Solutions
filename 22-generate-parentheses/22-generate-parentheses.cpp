class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate("",n,0,ret);
        return ret;
    }
    void generate(string s, int num, int close, vector<string>& ret) {
        if (num == 0 && close == 0) {
            ret.push_back(s);
            return;
        }
        if (num > 0) {
            generate(s + "(", num-1, close+1, ret);
        }
        if (close > 0) {
            generate(s + ")", num, close-1, ret);
        }
    }
};