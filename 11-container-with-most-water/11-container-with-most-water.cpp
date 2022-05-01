class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size()-1;
        int ret = 0;
        while (lo < hi) {
            ret = max(ret,min(height[hi],height[lo]) * (hi - lo));
            if (height[lo] < height[hi]) {
                lo++;
            } else {
                hi--;
            }
        }
        return ret;
    }
};