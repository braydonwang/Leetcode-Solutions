class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> v(n+1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                v[n]++;
            } else {
                v[citations[i]]++;
            }
        }
        int num = 0;
        for (int i = n; i >= 0; i--) {
            num += v[i];
            if (num >= i) {
                return i;
            }
        }
        return 0;
    }
};