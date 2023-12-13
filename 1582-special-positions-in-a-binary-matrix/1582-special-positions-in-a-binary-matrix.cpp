class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> r(m);
        vector<int> c(n);
        int res = 0;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j]) {
                    r[i] += 1;
                    c[j] += 1;
                }
            }
        }
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] and r[i] == 1 and c[j] == 1)
                    res += 1;
            }
        }
        
        return res;
    }
};