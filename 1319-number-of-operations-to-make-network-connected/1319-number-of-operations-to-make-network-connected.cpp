class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node) {
        if(vis[node]) return;
        vis[node] = 1;
        for(int n : adj[node]) {
            dfs(adj, vis, n);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) 
            return -1;
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        int comps = 0;
        for(auto& con : connections) {
            adj[con[0]].emplace_back(con[1]);
            adj[con[1]].emplace_back(con[0]);
        }
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                ++comps;
                dfs(adj, vis, i);
            }
        }
        return comps - 1;
    }
};