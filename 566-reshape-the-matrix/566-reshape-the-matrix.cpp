class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int oldR = mat.size(), oldC = mat[0].size();
        if (oldR * oldC != r * c) {
            return mat;
        }
        vector<vector<int>> ret(r,vector<int>(c));
        int indr = 0, indc = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ret[i][j] = mat[indr][indc];
                indc++;
                if (indc == oldC) {
                    indr++;
                    indc = 0;
                }
            }
        }
        return ret;
    }
};