class Solution {
public:
    void solve(vector<int>& res, int i, vector<vector<int>>& g, string& labels, int freq[]) 
    {
        if(res[i] == 0) {
            res[i] = 1;
            for(int val : g[i]) {
                int freq1[26] = {0};
                solve(res, val, g, labels, freq1);
                for(int j = 0; j < 26; ++j) {
                    freq[j] += freq1[j];
                }
            }
            res[i] = ++freq[labels[i] - 'a'];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n, 0);
        int freq[26] = {0};
        vector<vector<int>> graph(n);
        for(auto& ed : edges) {
            graph[ed[0]].emplace_back(ed[1]);
            graph[ed[1]].emplace_back(ed[0]);
        }
        solve(res, 0, graph, labels, freq);
        return res;
    }
};