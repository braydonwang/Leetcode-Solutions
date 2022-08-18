class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> v;
        vector<string> sorted;
        for (string str: words) {
            string s = "";
            for (char c: str) {
                char ch = order.find(c) + 'a';
                s += ch;
            }
            v.push_back(s);
            sorted.push_back(s);
        }
        sort(sorted.begin(),sorted.end());
        return v == sorted;
    }
};