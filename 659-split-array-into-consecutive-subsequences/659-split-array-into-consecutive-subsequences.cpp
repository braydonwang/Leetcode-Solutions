class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt;
        unordered_map<int,int> end;
        for (int num: nums) {
            cnt[num]++;
        }
        for (int num: nums) {
            if (!cnt[num]) {
                continue;
            }
            if (end[num-1] > 0) {
                end[num-1]--;
                end[num]++;
                cnt[num]--;
            } else if (cnt[num+1] && cnt[num+2]) {
                end[num+2]++;
                cnt[num]--;
                cnt[num+1]--;
                cnt[num+2]--;
            } else {
                return false;
            }
        }
        return true;
    }
};