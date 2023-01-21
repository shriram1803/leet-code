class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<int>& v, int curr, int& n){
        if(v[curr] > 0) return;
        v[curr]++;
        for(int i = 0; i < n; ++i){
            if(i != curr and g[curr][i] == 1)
                dfs(g, v, i, n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), res = 0;
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i){
            if(v[i] == 0)
                dfs(isConnected, v, i, n), res++;
        }
        return res;
    }
};