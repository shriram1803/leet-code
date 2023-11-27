class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> moves = {
        {2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}
    };
    const int rmax = 4, cmax = 3; 
    int f(int steps, int row, int col, vector<vector<vector<int>>>& dp) {
        if(steps == 1) {
            return 1;
        }
        if(dp[steps][row][col] != -1)
            return dp[steps][row][col];
            
        int local = 0;
        for(int i = 0; i < 8; ++i) {
            int r = row + moves[i][0], c = col + moves[i][1];            
            if(r < 0 or c < 0 or r >= rmax or c >= cmax) 
                continue;
            if(r == 3 and (c == 0 or c == cmax - 1))
                continue;
            local = ((long long)local + f(steps - 1, r, c, dp)) % mod;
        }
        
        return dp[steps][row][col] = local;
    }
    int knightDialer(int n) {
        int res = 0;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(3, -1)));
        
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(i == 3 and (j == 0 or j == cmax - 1))
                    continue;
                res = ((long long)res + f(n, i, j, dp)) % mod;
            }
        }
        
        return res;
    }
};