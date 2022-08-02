class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    bool search(int r, int c, int ind, string word, vector<vector<char>>& board) {
        if (ind == word.size() - 1) {
            return true;
        }
        int m = board.size(), n = board[0].size();
        bool found = false;
        for (int k = 0; k < 4; k++) {
            int newr = r + dir[k][0], newc = c + dir[k][1];
            if (newr >= 0 & newr < m && newc >= 0 && newc < n && board[newr][newc] == word[ind+1]) {
                char c = board[newr][newc];
                board[newr][newc] = '*';
                found |= search(newr,newc,ind+1,word,board);
                board[newr][newc] = c;
            }
        }
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    char c = board[i][j];
                    board[i][j] = '*';
                    if (search(i,j,0,word,board)) {
                        return true;
                    }
                    board[i][j] = c;
                }   
            }
        }
        return false;
    }
};