class Solution {
public:
    long long cnt = 0;
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int curr) {
        if(vis[curr] == 1)
            return;
        vis[curr] = 1;
        cnt += 1;
        for(int next : adj[curr]) {
            dfs(adj, vis, next);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res = 0;
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        long long visited_cnt = 0;
        for(auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        for(int i = 0; i < n; ++i) {
            if(vis[i] == 0) {
                dfs(adj, vis, i);
                res += (visited_cnt * cnt);
                visited_cnt += cnt;
                cnt = 0;
            }
        }
        return res;
    }
};