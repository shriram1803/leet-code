class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int prev) {
        if(color[node] == -1) {
            color[node] = !prev;
            for(int val : graph[node]) {
                if(!dfs(graph, color, val, color[node]))
                    return false;
            }
        } else {
            if(color[node] == prev) return false;
            else return true;
        }
            
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);        
        for(int i = 0; i < n; ++i) {
            if(color[i] == -1) {
                if(!dfs(graph, color, i, 1))
                    return false;
            }
        }
        return true;
    }
};