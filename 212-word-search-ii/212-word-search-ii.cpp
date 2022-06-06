class Solution {
    struct Trie {
        Trie* trie[26];
         string word = "";
         Trie() {
            for (int i = 0; i < 26; i++) {
                trie[i] = nullptr;
            }
         }  
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = build(words);
        vector<string> ans;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(i,j,board,root,ans);
            }
        }
        return ans;
    }
    Trie* build(vector<string>& words) {
        Trie* root = new Trie();
        Trie* cur = root;
        for (string s: words) {
            cur = root;
            for (char c: s) {
                if (!cur->trie[c-'a']) {
                    cur->trie[c-'a'] = new Trie();
                }
                cur = cur->trie[c-'a'];
            }
            cur->word = s;
        }
        return root;
    }  
    void dfs(int row, int col, vector<vector<char>>& board, Trie* cur, vector<string>& ans) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '#') {
            return;
        }
        char c = board[row][col];
        if (cur->trie[c-'a']) {
            cur = cur->trie[c-'a'];
            if ((cur->word).length() > 0 && find(ans.begin(), ans.end(), cur->word) == ans.end()) {
                ans.push_back(cur->word);
            }
            board[row][col] = '#';
            dfs(row+1,col,board,cur,ans);
            dfs(row-1,col,board,cur,ans);
            dfs(row,col+1,board,cur,ans);
            dfs(row,col-1,board,cur,ans);
            board[row][col] = c;
        }
    }
};