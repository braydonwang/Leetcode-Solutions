class Solution {
public:
    bool check(vector<int> a, vector<int> b) {
        for (int i = 0; i < a.size(); i++) {
            if (b[i] < a[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> a(58,0);
        vector<int> b(58,0);
        string ans = "";
        int min = 999999;
        for (int i = 0; i < t.length(); i++) {
            a[t[i]-'A']++;
        }
        int l = 0, r = 0;
        while (l <= r && r < s.length()) {
            while (check(a,b)) {
                if (min > r - l) {
                    min = r - l;
                    ans = s.substr(l,min);
                }
                b[s[l]-'A']--;
                l++;
            }
            b[s[r]-'A']++;
            r++;
        }
        while (check(a,b)) {
                if (min > r - l) {
                    min = r - l;
                    ans = s.substr(l,min);
                }
                b[s[l]-'A']--;
                l++;
            }
        return ans;
    }
};