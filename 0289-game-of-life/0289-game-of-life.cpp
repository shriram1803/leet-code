class Solution {
public:
    int isLive(vector<vector<int>>& temp, int m, int n, int i, int j) {
        if(i < 0 or j < 0 or i >= m or j >= n) return 0;
        if(temp[i][j] == 1) return 1;
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dirs{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
        };
        vector<vector<int>> temp = board;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int cnt = 0;
                for(auto& dir : dirs) {
                    cnt += isLive(temp, m, n, i + dir[0], j + dir[1]);
                }
                if(cnt == 3 or (temp[i][j] == 1 and cnt == 2)) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};