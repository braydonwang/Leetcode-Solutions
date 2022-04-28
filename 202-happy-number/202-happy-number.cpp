class Solution {
public:
    bool isHappy(int n) {
        int res = 0;
        vector<int> list;
        while (n != 1){
            res = 0;
            while (n != 0){
                res += (n % 10) * (n % 10);
                n /= 10;
            }
            n = res;
            if (std::count(list.begin(),list.end(),n)) {
                return false;
            }
            list.push_back(n);
        }
        return true;
    }
};