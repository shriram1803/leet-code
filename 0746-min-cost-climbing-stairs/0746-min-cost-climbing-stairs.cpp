class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        int prev = cost[0], pre = cost[1], temp = -1;
        for(int i = 2; i < n; ++i) {
            temp = cost[i] + min(pre, prev);
            prev = pre, pre = temp;
        }
        return min(pre, prev);
    }
};