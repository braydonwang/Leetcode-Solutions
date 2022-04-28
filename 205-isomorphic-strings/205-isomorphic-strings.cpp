class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        vector<char> list;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s.at(i), c2 = t.at(i);
            if (map.find(c1) == map.end()) {
                if (count(list.begin(),list.end(),c2)) {
                    return false;
                }
                map[c1] = c2;
                list.push_back(c2);
            } else {
                if ((map.find(c1))->second != c2) {
                    return false;
                }
            }
        }
        return true;
    }
};