class Solution {
public:
    int res = 1;
    int dfs(int ind, int n, vector<vector<int>>& g, string& s, vector<int>& v, char prev)
    {
        if(v[ind]) return 0;
        ++v[ind];
        int longest_path = 0;
        for(int val : g[ind]) {
            int curr = dfs(val, n, g, s, v, s[ind]);
            // cout << ind << " " << val << " " << curr << endl;
            res = max(res, 1 + curr + longest_path);
            longest_path = max(longest_path, curr);
        }
        --v[ind];
        if(s[ind] == prev) return 0;
        return 1 + longest_path;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);
        for(int i = 1; i < parent.size(); ++i) {
            graph[parent[i]].emplace_back(i);
        }
        dfs(0, n, graph, s, visited, 'A');
        return res;
    }
};