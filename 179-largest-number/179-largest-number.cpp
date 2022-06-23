class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for (int num: nums) {
            str.push_back(to_string(num));
        }
        sort(str.begin(),str.end(),[](string& s1, string& s2){return s1+s2 > s2+s1;});
        string ans = "";
        for (string s: str) {
            ans += s;
        }
        if (ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};