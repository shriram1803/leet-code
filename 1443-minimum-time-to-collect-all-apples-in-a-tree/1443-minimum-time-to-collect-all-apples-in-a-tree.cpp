class Solution {
public:
    int solve(int i, int n, vector<vector<int>>& v, vector<bool>& has, vector<int>& vi) {
        if(vi[i]) return 0;
        vi[i] = 1;
        int res = 0;
        for(int val : v[i]) {
            res += solve(val, n, v, has, vi);            
        }
        if(i != 0 and (has[i] or res > 0)) {
            ++res;
        }
        vi[i] = 0;
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> v(n);
        vector<int> vis(n, 0);
        for(auto& edge : edges) {
            int x = edge[0], y = edge[1];
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
        int val = solve(0, n, v, hasApple, vis);
        return 2 * val;
    }
};