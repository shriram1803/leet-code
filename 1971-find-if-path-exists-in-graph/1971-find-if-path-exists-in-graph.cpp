class Solution {
public:
    bool solve(vector<vector<int>> &graph, int cur, int dst, vector<int> &v) {
        if(v[cur]) return false;
        if(cur == dst) return true;
        ++v[cur];
        for(int val : graph[cur]) {
            if(solve(graph, val, dst, v))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);
        for(auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        return solve(graph, source, destination, visited);
    }
};