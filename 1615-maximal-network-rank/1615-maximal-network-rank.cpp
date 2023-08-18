class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<vector<bool>> g(n, vector<bool>(n));
        vector<int> counter(n);
        
        for(auto& road : roads) {
            g[road[0]][road[1]] = 1;
            g[road[1]][road[0]] = 1;
            counter[road[0]] += 1;
            counter[road[1]] += 1;
        }
        
        int maxi = -1;
        
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(g[i][j]) {
                    maxi = max(maxi, counter[i] + counter[j] - 1);
                } else {
                    maxi = max(maxi, counter[i] + counter[j]);
                }
            }
        }
        
        return maxi;
    }
};