class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int count = 1;
        while (count < n) {
            string temp = "";
            char prev = 'a';
            int cnt = 0;
            for (char c: s) {
                if (prev == 'a') {
                    prev = c;
                    cnt = 1;
                } else if (prev != c) {
                    temp += (cnt + '0');
                    temp += prev;
                    prev = c;
                    cnt = 1;
                }  else {
                    cnt++;
                }
            }
            temp += (cnt + '0');
            temp += prev;
            s = temp;
            count++;
        }
        return s;
    }
};