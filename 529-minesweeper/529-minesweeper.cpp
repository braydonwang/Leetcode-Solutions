class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    void dfs(int r, int c, vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            int newr = r + dir[i][0], newc = c + dir[i][1];
            if (newr >= 0 && newr < board.size() && newc >= 0 && newc < board[0].size() && board[newr][newc] == 'M') {
                count++;
            }
        }
        if (count > 0) {
            board[r][c] = (count + '0');
        } else {
            board[r][c] = 'B';
            for (int i = 0; i < 8; i++) {
                int newr = r + dir[i][0], newc = c + dir[i][1];
                if (newr >= 0 && newr < board.size() && newc >= 0 && newc < board[0].size() && board[newr][newc] == 'E') {
                    dfs(newr,newc,board);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int cr = click[0], cc = click[1];
        if (board[cr][cc] == 'M') {
            board[cr][cc] = 'X';
            return board;
        }
        dfs(cr,cc,board);
        return board;
    }
};