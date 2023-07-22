class Solution {
public:
    vector<vector<string>> res;
    void backtrack(vector<string>& curr, unordered_set<int>& a, unordered_set<int>& b, vector<int>& c, int n, const int N) 
    {
        
        if(n < 0) {
            res.emplace_back(curr);
            return;
        }
        
        for(int i = 0; i < N; ++i) {
            if(a.count(n - i) or b.count(n + i) or c[i] == 1)
                continue;
            
            a.insert(n - i);
            b.insert(n + i);
            c[i] = 1;
            curr[n][i] = 'Q';
            
            backtrack(curr, a, b, c, n - 1, N);
            
            a.erase(n - i);
            b.erase(n + i);
            c[i] = 0;
            curr[n][i] = '.';
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        
        string init_row = "";
        for(int i = 0; i < n; ++i)
            init_row += '.';
        
        vector<string> init(n, init_row);
        unordered_set<int> a, b;
        vector<int> c(n);
        
        backtrack(init, a, b, c, n - 1, n);

        return res;
    }
};