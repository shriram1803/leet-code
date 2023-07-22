class Solution {
public:
    int backtrack(vector<int>& diag1, vector<int>& diag2, vector<int>& down, int n, const int N) 
    {
        
        if(n < 0) {
            return 1;
        }
        
        int res = 0;
        
        for(int i = 0; i < N; ++i) {
            
            if(diag1[N + (n - i)] or diag2[n + i] or down[i])
                continue;
            
            diag1[N + (n - i)] = 1;
            diag2[n + i] = 1;
            down[i] = 1;
            
            res += backtrack(diag1, diag2, down, n - 1, N);
            
            diag1[N + (n - i)] = 0;
            diag2[n + i] = 0;
            down[i] = 0;
            
        }
        
        return res;
        
    }
    int totalNQueens(int n) {
        
        vector<int> down(n), diag1(2 * n), diag2(2 * n + 1);
        
        return backtrack(diag1, diag2, down, n - 1, n);
    }
};