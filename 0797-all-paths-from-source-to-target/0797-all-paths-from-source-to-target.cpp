class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            if(curr.back() == n - 1) {
                res.emplace_back(curr);
                continue;
            }
            for(int val : graph[curr.back()]) {
                curr.emplace_back(val);
                q.push(curr);
                curr.pop_back();
            }
        }
        return res;
    }
};