class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size(), N = m + n;
        string res(N, ' ');
        int ind = 0;
        
        for(int i = 0; i < min(m, n); ++i) {
            res[ind++] = word1[i];
            res[ind++] = word2[i];
        }
        
        for(int i = min(m, n); i < m; ++i) {
            res[ind++] = word1[i];
        }
        
        for(int j = min(m, n); j < n; ++j) {
            res[ind++] = word2[j];
        }
        
        return res;
    }
};