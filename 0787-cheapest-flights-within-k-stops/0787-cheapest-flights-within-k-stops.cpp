typedef pair<int, int> PR;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        vector<vector<pair<int, int>>> adj(n);
        deque<array<int, 3>> dq;
        for(auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        dq.push_back({src, 0, k}), cost[src] = 0;
        while(!dq.empty()) {
            auto [curr_node, curr_cost, K] = dq.front(); dq.pop_front();
            for(auto& it : adj[curr_node]) {
                int next_cost = it.second, next_node = it.first;
                if(K > -1 and cost[next_node] > curr_cost + next_cost) {
                    cost[next_node] = curr_cost + next_cost;
                    dq.push_back({next_node, cost[next_node], K - 1});
                }
            }            
    }
        if(cost[dst] != INT_MAX) return cost[dst];
        return -1;
    }
};