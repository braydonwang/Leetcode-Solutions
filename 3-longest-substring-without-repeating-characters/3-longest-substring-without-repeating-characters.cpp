class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int start = 0, ans = 0;
        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
            while (map[s[i]] > 1) {
                map[s[start]]--;
                start++;
            }
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};