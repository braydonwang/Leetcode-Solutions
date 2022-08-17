class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> set;
        vector<string> v{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (string s: words) {
            string str = "";
            for (char c: s) {
                str += v[c-'a'];
            }
            set.insert(str);
        }
        return set.size();
    }
};