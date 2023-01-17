class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>& color, int start) {
        color[start] = 0;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int temp = q.front(); q.pop();
            for(int val : graph[temp]) {
                if(color[val] == -1) {
                    color[val] = abs(color[temp] - 1);
                    q.push(val);
                } else {
                    if(color[val] == color[temp]) 
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);        
        for(int i = 0; i < n; ++i) {
            if(color[i] == -1) {
                if(!bfs(graph, color, i))
                    return false;
            }
        }
        return true;
    }
};