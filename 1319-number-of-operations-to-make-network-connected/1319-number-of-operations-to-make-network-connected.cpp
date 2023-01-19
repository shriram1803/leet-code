class Solution {
public:
    int cycles = 0;
    void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, int node, int prev) {
        if(path[node]) {
            ++cycles;
            return;
        } 
        if(vis[node]) return;
        vis[node] = 1, path[node] = 1;
        
        for(int n : adj[node]) {
            if(n == prev) continue;
            dfs(adj, vis, path, n, node);
        }
        
        path[node] = 0;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0), path(n, 0);
        int comps = 0;
        for(auto& con : connections) {
            adj[con[0]].emplace_back(con[1]);
            adj[con[1]].emplace_back(con[0]);
        }
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                ++comps;
                dfs(adj, vis, path, i, -1);
            }
        }
        if(cycles >= comps - 1) return comps - 1;
        return -1;
    }
};