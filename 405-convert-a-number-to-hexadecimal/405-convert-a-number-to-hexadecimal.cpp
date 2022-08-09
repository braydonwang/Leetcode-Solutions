class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string hex = "0123456789abcdef";
        string ans = "";
        unsigned n = num;
        while (n) {
            ans = hex[n & 0xf] + ans;
            n >>= 4;
        }
        return ans;
    }
};