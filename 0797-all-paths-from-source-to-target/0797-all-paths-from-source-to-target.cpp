class Solution {
public:
    void dfs(int n, vector<vector<int>>& graph, vector<int>& curr, vector<vector<int>>& res) 
    {
        if(curr.back() == n - 1) {
            res.emplace_back(curr);
            return;
        }
        for(int val : graph[curr.back()]) {
            curr.emplace_back(val);
            dfs(n, graph, curr, res);
            curr.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> v{ 0 };
        dfs(n, graph, v, res);
        return res;
    }
};