class Solution {
public:
    string defangIPaddr(string address) {
        string ret = "";
        for (char c: address) {
            if (c == '.') {
                ret += "[.]";
            } else {
                ret += c;
            }
        }
        return ret;
    }
};