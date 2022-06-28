class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        int ans = 0;
        for (int i = 2; i*i < n; i++) {
            if (prime[i]) {
                int temp = i*i;
                while (temp < n) {
                    prime[temp] = false;
                    temp += i;
                }
            }
        }
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
            }
        }
        return ans;
    }
};