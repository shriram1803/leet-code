class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        vector<vector<pair<int, int>>> adj(n);
        for(auto& e : redEdges) {
            adj[e[0]].push_back({e[1], 0});
        }
        for(auto& e : blueEdges) {
            adj[e[0]].push_back({e[1], 1});
        }
        deque<array<int, 3>> dq;
        res[0] = 0;
        dq.push_back({0, -1, 0});
        while(!dq.empty()) {
            auto [node, color, d] = dq.front();
            dq.pop_front();
            if(res[node] == -1 or d < res[node]) res[node] = d;
            for(auto& it : adj[node]) {
                if(it.second != color and it.first != -1) {
                    dq.push_back({it.first, it.second, d + 1});
                    it.first = -1;
                }
            }            
        }
        return res;
    }
};