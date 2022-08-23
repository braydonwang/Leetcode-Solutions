class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for (int i = 1; i <= 26; i++) {
            int l = 0, r = 0;
            int cnt = 0, good = 0;
            vector<int> freq(26);
            while (r < s.length()) {
                if (cnt <= i) {
                    freq[s[r]-'a']++;
                    if (freq[s[r]-'a'] == 1) {
                        cnt++;
                    }
                    if (freq[s[r]-'a'] == k) {
                        good++;
                    }
                    r++;
                } else {
                    freq[s[l]-'a']--;
                    if (freq[s[l]-'a'] == 0) {
                        cnt--;
                    }
                    if (freq[s[l]-'a'] == k - 1) {
                        good--;
                    }
                    l++;
                }
                if (cnt == i && good == i) {
                    ans = max(ans,r-l);
                }
            }
        }
        return ans;
    }
};