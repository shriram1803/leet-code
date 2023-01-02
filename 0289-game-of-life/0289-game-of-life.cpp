class Solution {
public:
    int isLive(vector<vector<int>>& board, int m, int n, int i, int j) {
        if(i < 0 or j < 0 or i >= m or j >= n) return 0;
        if(board[i][j] == 1 or board[i][j] == 2) return 1;
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int cnt = 0;
                for(auto& dir : dirs) {
                    cnt += isLive(board, m, n, i + dir[0], j + dir[1]);
                }
                if(cnt == 3) {
                    if(board[i][j] == 0) {
                        board[i][j] = 3;
                    }
                } else if(cnt != 2) {
                    if(board[i][j] == 1) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 3) {
                    board[i][j] = 1;
                } else if(board[i][j] == 2) {
                    board[i][j] = 0;
                }
            }
        }
    }
};