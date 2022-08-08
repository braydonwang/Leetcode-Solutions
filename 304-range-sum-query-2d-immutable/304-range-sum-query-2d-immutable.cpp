class NumMatrix {
public:
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        pre = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1));
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        cout << row1 << " " << col1 << " " << row2 << " " << col2 << endl;
        return pre[row2+1][col2+1] - pre[row1][col2+1] - pre[row2+1][col1] + pre[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */