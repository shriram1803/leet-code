class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        int res = 0;
        
        for(auto& g : grid) {
            sort(g.begin(), g.end(), greater<int>());
        }
        
        for(int i = 0; i < grid[0].size(); ++i) {
            
            int maxx = INT_MIN;
            
            for(int j = 0; j < grid.size(); ++j) {
                maxx = max(maxx, grid[j][i]);
            }
            
            res += maxx;
            
        }
        
        return res;
    }
};