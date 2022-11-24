class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int r, int c, const int m, const int n){
        if(i >= word.size())
            return true;
        if(r < 0 or c < 0 or r >= m or c >= n or board[r][c] != word[i])
            return false;
        board[r][c] = '0';
        bool res = dfs(board, word, i+1, r + 1,c, m, n) or
            dfs(board, word, i+1, r - 1, c, m, n) or
            dfs(board, word, i+1, r ,c + 1, m, n) or
            dfs(board, word, i+1, r ,c - 1, m, n);
        board[r][c] = word[i];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, 0, i ,j, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};