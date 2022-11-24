class Solution {
public:
    bool bfs(vector<vector<char>>& board, vector<vector<int>>& dp, string word, int i, int r, int c, const int m, const int n){
        if(i >= word.size())
            return true;
        if(r < 0 or c < 0 or r >= m or c >= n or board[r][c] != word[i] or dp[r][c])
            return false;
        dp[r][c]++;
        bool res = bfs(board, dp, word, i+1, r + 1,c, m, n) or
            bfs(board, dp, word, i+1, r - 1, c, m, n) or
            bfs(board, dp, word, i+1, r ,c + 1, m, n) or
            bfs(board, dp, word, i+1, r ,c - 1, m, n);
        dp[r][c]--;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(bfs(board, dp, word, 0, i ,j, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};