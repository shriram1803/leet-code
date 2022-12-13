class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int val = matrix[i - 1][j];
                if(j > 0) val = min(val, matrix[i - 1][j - 1]);
                if(j < m - 1) val = min(val, matrix[i - 1][j + 1]);
                matrix[i][j] += val;
            }
        }
        for(int i = 0; i < n; ++i){
            res = min(res, matrix[m - 1][i]);
        }
        return res;
    }
};