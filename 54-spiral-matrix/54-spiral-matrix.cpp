class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> numSteps{cols, rows-1};
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int indDir = 0;
        int i = 0, j = -1;
        vector<int> ans;
        while (numSteps[indDir%2]) {
            for (int k = 0; k < numSteps[indDir%2]; k++) {
                i += dir[indDir][0]; j += dir[indDir][1];
                ans.push_back(matrix[i][j]);
            }
            numSteps[indDir%2]--;
            indDir = (indDir + 1) % 4;
        }
        return ans;
    }
};