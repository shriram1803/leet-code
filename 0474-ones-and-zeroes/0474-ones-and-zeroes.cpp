class Solution {
public:
    int f(int ind, int i, int j, vector<string>& strs, vector<vector<vector<int>>>& dp) {
        if(ind < 0)
            return 0;
        if(i == 0 and j == 0)
            return 0;
        
        if(dp[ind][i][j] != -1)
            return dp[ind][i][j];
        
        int not_pick = f(ind - 1, i, j, strs, dp);
        
        int tmpi = i, tmpj = j;
        for(int k = 0; k < strs[ind].size(); ++k)
            if(strs[ind][k] == '0')
                i -= 1;
            else
                j -= 1;
        
        if(i < 0 or j < 0)
            return not_pick;
        
        
        int pick = 1 + f(ind - 1, i, j, strs, dp);
        
        return dp[ind][tmpi][tmpj] = max(not_pick, pick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        return f(N - 1, m, n, strs, dp);
    }
};