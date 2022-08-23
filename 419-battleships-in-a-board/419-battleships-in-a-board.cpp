class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r, int c, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '.') {
            return;
        }
        board[r][c] = '.';
        for (int i = 0; i < 4; i++) {
            dfs(r+dir[i][0],c+dir[i][1],board);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X') {
                    count++;
                    dfs(i,j,board);
                }
            }
        }
        return count;
    }
};