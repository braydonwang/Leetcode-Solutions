class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;
                int temp = i+i;
                while (temp < n) {
                    prime[temp] = false;
                    temp += i;
                }
            }
        }
        return ans;
    }
};