class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        int a = 0, b = 1, c = 0;
        for (int i = 2; i <= n; i++) {
            c = a;
            a = b;
            b = c + b;
        }
        return b;
    }
};