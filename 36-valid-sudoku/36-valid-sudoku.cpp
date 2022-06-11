class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> vec(9);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                vec[board[i][j]-'1']++;
                if (vec[board[i][j]-'1'] > 1) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<int> vec(9);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                vec[board[j][i]-'1']++;
                if (vec[board[j][i]-'1'] > 1) {
                    return false;
                }
            }
        }
        int i = 0, j = 0;
        while (i <= 6) {
            vector<int> vec(9);
            for (int k = i; k < i+3; k++) {
                for (int l = j; l < j+3; l++) {
                    if (board[k][l] == '.') {
                        continue;
                    }
                    vec[board[k][l]-'1']++;
                    if (vec[board[k][l]-'1'] > 1) {
                        return false;
                    }
                }
            }
            j += 3;
            if (j > 6) {
                i += 3;
                j = 0;
            }
        }
        return true;
    }
};