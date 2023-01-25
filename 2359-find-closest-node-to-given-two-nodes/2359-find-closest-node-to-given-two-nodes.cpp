class Solution {
public:
    int res = -1;
    void dfs(vector<int>& edges, vector<int>& vis, int curr, int steps, vector<int>& dst) 
    {
        if(vis[curr]) return;
        vis[curr] = 1, dst[curr] = steps;
        if(edges[curr] != -1) 
            dfs(edges, vis, edges[curr], steps + 1, dst);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), res = -1, minn = INT_MAX;
        
        vector<int> vis(n, 0), dst(n, -1), dst1(n, -1);
        dfs(edges, vis, node1, 0, dst);
        fill(vis.begin(), vis.end(), 0);
        dfs(edges, vis, node2, 0, dst1);
        
        for(int i = 0; i < n; ++i) {
            if(dst[i] == -1 or dst1[i] == -1) continue;
            int val = max(dst[i], dst1[i]);
            if(val < minn) {
                res = i, minn = val;
            }
        }
        return res;
    }
};