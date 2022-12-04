class Solution {
public:
    int res = INT_MAX;
    
    void solve(int n, vector<vector<pair<int, int>>>& m, vector<int>& v, int curr) {
        if(curr == n or v[curr] > 0) return;
        v[curr]++;
        for(auto &[val, cos] : m[curr]) {
            res = min(res, cos);
            solve(n, m, v, val);           
        }        
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> m(n + 1);
        
        for(auto& road : roads) {
            m[road[0]].push_back({road[1], road[2]});
            m[road[1]].push_back({road[0], road[2]});
        }
        
        vector<int> v(n + 1, 0);
        
        solve(n, m, v, 1);
        
        return res;
    }
};