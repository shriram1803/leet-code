class Solution {
public:
    bool dfs(vector<vector<int>>& g, vector<int>& vis, vector<int>& path, int i, vector<int>& isCycle) {
        if(path[i] or isCycle[i]) return true;
        if(vis[i]) return false;
        path[i] = 1, vis[i] = 1;
        bool res = false;
        for(int val : g[i]) {
            if(dfs(g, vis, path, val, isCycle)) {
                res = true;
                isCycle[val] = 1;
            }
        }
        path[i] = 0;
        return res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path(n, 0), vis(n, 0), res;
        vector<int> isCycle(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i])
                if(dfs(graph, vis, path, i, isCycle))
                    isCycle[i] = 1;
        }
        for(int i = 0; i < n; ++i) {
            if(isCycle[i]) continue;
            res.emplace_back(i);
        }
        return res;
    }
};