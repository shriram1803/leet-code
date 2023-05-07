class Solution {
public:
    int res = 0;
    int dfs(vector<int>& cost, int curr, int n) {
        if(curr > n)
            return 0;
        int left = dfs(cost, curr * 2, n);
        int right = dfs(cost, curr * 2 + 1, n);
        res += abs(left - right);
        return cost[curr - 1] + max(left, right);
    }
    int minIncrements(int n, vector<int>& cost) {
        dfs(cost, 1, n);
        return res;
    }
};