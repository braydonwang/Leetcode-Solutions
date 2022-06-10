class Solution {
public:
    vector<vector<char>> letters = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.length() == 0) {
            return ret;
        }
        combine("", digits, ret);
        return ret;
    }
    void combine(string s, string digits, vector<string>& ret) {
        if (digits.length() == 0) {
            ret.push_back(s);
            return;
        }
        int ind = digits[0]-'2';
        for (char c: letters[ind]) {
            combine(s + c, digits.substr(1), ret);
        }
    }
};