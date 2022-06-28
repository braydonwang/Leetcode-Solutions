class Solution {
public:
    vector<vector<int>> ans;
    void combination(int num, int k, int n, vector<int> vec) {
        if (vec.size() == k) {
            if (n == 0) {
                ans.push_back(vec);
            }
            return;
        }
        if (n < 0 || num > 9) {
            return;
        }
        combination(num+1,k,n,vec);
        vec.push_back(num);
        combination(num+1,k,n-num,vec);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        combination(1,k,n,vec);
        return ans;
    }
};