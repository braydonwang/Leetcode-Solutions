class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size()-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if ((mid-1 < 0 || arr[mid] > arr[mid-1]) && (mid+1 >= arr.size() || arr[mid] > arr[mid+1])) {
                return mid;
            } else if (mid-1 >= 0 && arr[mid] < arr[mid-1]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return 0;
    }
};