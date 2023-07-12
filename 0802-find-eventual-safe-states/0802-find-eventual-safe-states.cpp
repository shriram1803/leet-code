class Solution {
public:
    int isCycle(vector<vector<int>>& g, vector<int>& path, vector<int>& vis, vector<int>& cycleEle, int curr) {
        if(path[curr] or cycleEle[curr])
            return 1;
        if(vis[curr])
            return 0;
        
        vis[curr] = 1, path[curr] = 1;
        
        for(auto& node : g[curr]) {
            if(isCycle(g, path, vis, cycleEle, node)) {
                cycleEle[curr] = 1;
            }
        }
        
        path[curr] = 0;
        
        return cycleEle[curr];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n), cycleEles(n), res;
        for(int i = 0; i < n; ++i) {
            vector<int> path(n);
            if(!vis[i])
                isCycle(graph, path, vis, cycleEles, i);
        }
        
        for(int i = 0; i < n; ++i) {
            if(!cycleEles[i])
                res.emplace_back(i);
        }
        
        return res;
    }
};