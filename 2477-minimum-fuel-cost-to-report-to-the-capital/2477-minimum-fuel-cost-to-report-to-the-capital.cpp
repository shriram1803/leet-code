class Solution {
public:
    long long res = 0;
    int dfs(unordered_map<int, vector<int>>& m, int curr, int prev, int seats) {
        
        int children = 1;
        
        for(int child : m[curr]) {
            if(child == prev) continue;
            int val = dfs(m, child, curr, seats);
            res += ceil(val / (double)seats);
            children += val;
        }
        
        return children;
        
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> m;
        for(auto& road : roads) {
            m[road[0]].emplace_back(road[1]);
            m[road[1]].emplace_back(road[0]);
        }
        dfs(m, 0, -1, seats);
        return res;
    }
};