class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> prev(2, 0), curr(2, 0);
        
        for(int ind = n - 1; ind >= 0; --ind) {
            curr[0] = max(prev[0], prices[ind] + prev[1]);
            curr[1] = max(prev[1], -prices[ind] + prev[0]);
            prev = curr;
        }
        
        return prev[1];
    }
};