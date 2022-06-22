class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26);
        unordered_set<int> set;
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i]-'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) {
                continue;
            }
            if (set.find(cnt[i]) == set.end()) {
                set.insert(cnt[i]);
                continue;
            }
            while (set.find(cnt[i]) != set.end()) {
                cnt[i]--;
                ans++;
            }
            if (cnt[i] != 0) {
                set.insert(cnt[i]);
            }
        }
        return ans;
    }
};