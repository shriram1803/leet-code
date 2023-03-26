class Solution {
public:
    int longest = -1;
    void dfs(vector<int>& edges, vector<int>& path, int curr, int dst) {
        if(path[curr] != -1) {
            longest = max(longest, dst - path[curr]);
            return;
        }
        if(edges[curr] == -1)
            return;
        int next = edges[curr];
        path[curr] = dst, edges[curr] = -1;
        dfs(edges, path, next, dst + 1);
        path[curr] = -1;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0), path(n, -1);
        for(int i = 0; i < n; ++i) {
            if(edges[i] != -1)
                dfs(edges, path, i, 0);
        }
        return longest;
    }
};