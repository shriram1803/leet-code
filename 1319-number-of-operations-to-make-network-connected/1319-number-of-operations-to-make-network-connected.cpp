class Solution {
public:
    int cycles = 0;
    void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, int curr, int prev) {
        if(path[curr]) {
            cycles += 1;
            return;
        }
        if(vis[curr]) {
            return;
        }
        vis[curr] = 1, path[curr] = 1;
        for(int next : adj[curr]) {
            if(next != prev)
                dfs(adj, vis, path, next, curr);
        }
        path[curr] = 0;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0), path(n, 0);
        for(auto& conn : connections) {
            adj[conn[0]].emplace_back(conn[1]);
            adj[conn[1]].emplace_back(conn[0]);
        }
        int comps = 0;
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) {
                dfs(adj, vis, path, i, -1);
                comps += 1;
            }
        }
        if(cycles < comps - 1)
            return -1;
        return comps - 1;
    }
};