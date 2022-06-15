
bool compare(string a, string b) {
        return (a.length() < b.length());
    }
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int ans = 1;
        unordered_map<string,int> dp;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                string str = words[i].substr(0,j) + words[i].substr(j+1);
                dp[words[i]] = max(dp[words[i]], dp.find(str) != dp.end() ? dp[str] + 1 : 1);
                ans = max(ans,dp[words[i]]);
            }
        }
        return ans;
    }
};