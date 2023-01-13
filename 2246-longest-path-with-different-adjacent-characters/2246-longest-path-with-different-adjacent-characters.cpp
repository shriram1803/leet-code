class Solution {
public:
    int res = 1;
    int dfs(int ind, int n, vector<vector<int>>& g, string& s, char prev)
    {
        int longest_path = 0;
        for(int val : g[ind]) {
            if(ind == val) continue;
            int curr = dfs(val, n, g, s, s[ind]);
            res = max(res, 1 + curr + longest_path);
            longest_path = max(longest_path, curr);
        }
        if(s[ind] == prev) return 0;
        return 1 + longest_path;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> graph(n);
        for(int i = 1; i < parent.size(); ++i) {
            graph[parent[i]].emplace_back(i);
        }
        dfs(0, n, graph, s, 'A');
        return res;
    }
};