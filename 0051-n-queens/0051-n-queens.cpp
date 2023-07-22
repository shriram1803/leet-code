class Solution {
public:
    vector<vector<string>> res;
    void backtrack(vector<string>& curr, vector<int>& diag1, vector<int>& diag2, vector<int>& down, int n, const int N) 
    {
        
        if(n < 0) {
            res.emplace_back(curr);
            return;
        }
        
        for(int i = 0; i < N; ++i) {
            
            if(diag1[N + (n - i)] or diag2[n + i] or down[i])
                continue;
            
            diag1[N + (n - i)] = 1;
            diag2[n + i] = 1;
            down[i] = 1;
            curr[n][i] = 'Q';
            
            backtrack(curr, diag1, diag2, down, n - 1, N);
            
            diag1[N + (n - i)] = 0;
            diag2[n + i] = 0;
            down[i] = 0;
            curr[n][i] = '.';
            
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        string init_row = "";
        for(int i = 0; i < n; ++i)
            init_row += '.';
        
        vector<string> init(n, init_row);
        vector<int> down(n), diag1(2 * n), diag2(2 * n + 1);
        
        backtrack(init, diag1, diag2, down, n - 1, n);

        return res;
    }
};