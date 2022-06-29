class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int count = 1;
        bool any = false;
        while (matrix.size() && matrix[0].size()) {
            vector<vector<char>> temp(matrix.size()-1);
            bool has = false;
            for (int i = 0; i < matrix.size()-1; i++) {
                for (int j = 0; j < matrix[0].size()-1; j++) {
                    if (matrix[i][j] == '1' || matrix[i][j+1] == '1' || matrix[i+1][j] == '1' || matrix[i+1][j+1] == '1') {
                        any = true;
                    }
                    if (matrix[i][j] == '1' && matrix[i][j+1] == '1' && matrix[i+1][j] == '1' && matrix[i+1][j+1] == '1') {
                        temp[i].push_back('1');
                        has = true;
                    } else {
                        temp[i].push_back('0');
                    }
                }
            }
            if (!has) {
                break;
            }
            count++;
            matrix = temp;
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    return count*count;
                }
            }
        }
        return any ? count*count : 0;
    }
};