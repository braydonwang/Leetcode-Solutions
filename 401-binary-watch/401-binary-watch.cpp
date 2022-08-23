class Solution {
public:
    vector<int> v{8,4,2,1,-32,-16,-8,-4,-2,-1};
    vector<string> ans;
    void find(int hour, int min, int num, int ind) {
        if (num == 0) {
            if (min < 60 && hour < 12) {
                if (min < 10) {
                    ans.push_back(to_string(hour) + ":0" + to_string(min));
                } else {
                    ans.push_back(to_string(hour) + ":" + to_string(min));
                }
            }
            return;
        }
        if (ind > 9) {
            return;
        }
        find(hour,min,num,ind+1);
        if (v[ind] < 0) {
            find(hour,min-v[ind],num-1,ind+1);
        } else {
            find(hour+v[ind],min,num-1,ind+1);
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        find(0,0,turnedOn,0);
        return ans;
    }
};