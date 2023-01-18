class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int>& vis, vector<int>& path, int i) {
        if(path[i]) return true;
        if(vis[i]) return false;
        path[i] = 1, vis[i] = 1;
        bool res = false;
        for(int val : g[i]) {
            if(dfs(g, vis, path, val)) {
                res = true;
            }
        }
        if(res) return true;
        path[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path(n, 0), vis(n, 0), res;
        for(int i = 0; i < n; ++i) {
            if(!vis[i])
                dfs(graph, vis, path, i);
        }
        for(int i = 0; i < n; ++i) {
            if(path[i]) continue;
            res.emplace_back(i);
        }
        return res;
    }
};