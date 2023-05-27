class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        int n = matrix.size();
        for(int i = n - 2; i >= 0; --i){
            for(int j = 0; j < n; ++j){
                int val = matrix[i + 1][j];
                if(j > 0) val = min(val, matrix[i + 1][j - 1]);
                if(j < n - 1) val = min(val, matrix[i + 1][j + 1]);
                matrix[i][j] += val;
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};