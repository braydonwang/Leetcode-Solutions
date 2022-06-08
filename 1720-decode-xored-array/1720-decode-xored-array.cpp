class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ret;
        ret.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            ret.push_back(ret.back() ^ encoded[i]);
        }
        return ret;
    }
};