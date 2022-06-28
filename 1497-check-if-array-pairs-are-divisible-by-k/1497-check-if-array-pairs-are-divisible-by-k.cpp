class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mod(k);
        for (int i = 0; i < arr.size(); i++) {
            mod[arr[i]%k < 0 ? arr[i]%k+k : arr[i]%k]++;
        }
        if (mod[0] % 2 != 0) {
            return false;
        }
        for (int i = 1; i < k; i++) {
            if (mod[i] != mod[k-i]) {
                return false;
            }
        }
        return true;
    }
};