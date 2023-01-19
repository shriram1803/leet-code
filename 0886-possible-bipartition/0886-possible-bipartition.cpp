class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int curr) {   
        for(int node : adj[curr]) {
            if(color[node] == color[curr])
                return true;
            if(color[node] != -1) continue;
            color[node] = !color[curr];
            if(dfs(adj, color, node))
                return true;
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        vector<int> color(n + 1, -1);
        for(auto &d : dislikes) {
            adj[d[0]].emplace_back(d[1]);
            adj[d[1]].emplace_back(d[0]);
        }
        for(int i = 1; i <= n; ++i) {
            if(color[i] != -1) continue;
            color[i] = 0;
            if(dfs(adj, color, i))
                return false;
        }
        return true;
    }
};