class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> has_no_indegree(n, true);
        vector<int> res;
        for(auto& edge : edges) {
            has_no_indegree[edge[1]] = false;
        }
        for(int i = 0; i < n; ++i) {
            if(has_no_indegree[i])
                res.emplace_back(i);
        }
        return res;
    }
};