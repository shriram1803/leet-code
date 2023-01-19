class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& color, int curr, int prev) {        
        if(vis[curr] == 1) {
            if(color[curr] == prev)
                return true;
            return false;
        }
        vis[curr] = 1, color[curr] = !prev;
        for(int node : adj[curr]) {
            if(node == curr) continue;            
            if(dfs(adj, vis, color, node, color[curr]))
                return true;
        }
        return false;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        vector<int> vis(n + 1, 0), color(n + 1, -1);
        for(auto &d : dislikes) {
            adj[d[0]].emplace_back(d[1]);
            adj[d[1]].emplace_back(d[0]);
        }
        for(int i = 1; i <= n; ++i) {
            if(vis[i] == 1) continue;
            if(dfs(adj, vis, color, i, 1))
                return false;
        }
        return true;
    }
};