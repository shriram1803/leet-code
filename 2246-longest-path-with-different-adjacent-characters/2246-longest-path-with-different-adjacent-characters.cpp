class Solution {
public:
    int res = 1;
    int dfs(int ind, vector<vector<int>>& g, string& s, char prev)
    {
        int longest_path = 0;
        for(int val : g[ind]) {
            if(ind == val) continue;
            int curr = dfs(val, g, s, s[ind]);
            res = max(res, 1 + curr + longest_path);
            longest_path = max(longest_path, curr);
        }
        if(s[ind] == prev) return 0;
        return 1 + longest_path;
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> graph(s.size());
        for(int i = 1; i < parent.size(); ++i) {
            graph[parent[i]].emplace_back(i);
        }
        dfs(0, graph, s, 'A');
        return res;
    }
};