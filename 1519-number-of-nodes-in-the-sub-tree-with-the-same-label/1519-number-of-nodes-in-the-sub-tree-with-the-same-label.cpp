class Solution {
public:
    void solve(vector<int>& res, int i, int n, vector<vector<int>>& g, string& labels, vector<bool>& vi, vector<int>& freq) 
    {
        if(vi[i]) return;
        vi[i] = true;
        int asci = labels[i] - 'a';
        ++freq[asci];
        int curr = freq[asci];
        int tot = 0;
        for(int val : g[i]) {
            if(val == i) continue;
            solve(res, val, n, g, labels, vi, freq);
            tot += freq[asci] - curr;
            res[i] += freq[asci] - curr;
            freq[asci] = curr;
        }
        freq[asci] = curr + tot;
        vi[i] = false;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n, 1), freq(26, 0);
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for(auto& ed : edges) {
            graph[ed[0]].emplace_back(ed[1]);
            graph[ed[1]].emplace_back(ed[0]);
        }
        solve(res, 0, n, graph, labels, visited, freq);
        return res;
    }
};