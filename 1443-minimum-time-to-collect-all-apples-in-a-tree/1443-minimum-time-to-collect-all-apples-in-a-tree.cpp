class Solution {
public:
    int solve(int i, int n, vector<vector<int>>& v, vector<bool>& has, vector<int>& vi) {
        if(vi[i]) return 0;
        int res = 0;
        vi[i] = 1;
        for(int val : v[i]) {
            res += solve(val, n, v, has, vi);            
        }
        vi[i] = 0;
        if(i != 0 and (has[i] or res > 0)) {
            ++res;
        }
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> v(n);
        vector<int> vis(n, 0);
        for(auto& edge : edges) {
            v[edge[0]].emplace_back(edge[1]);
            v[edge[1]].emplace_back(edge[0]);
        }
        return 2 * solve(0, n, v, hasApple, vis);
    }
};