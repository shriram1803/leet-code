class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // Modified previous version
        // Just changed loop count of inner loop to K
        int n = prices.size();
        
        const bool canBuy = 1;
        
        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int rem = 1; rem <= k; ++rem) {
                curr[canBuy][rem] = max(prev[canBuy][rem], -prices[ind] + prev[!canBuy][rem]);
                
                curr[!canBuy][rem] = max(prev[!canBuy][rem], prices[ind] + prev[canBuy][rem - 1]);
            }
            prev = curr;
        } 
        
        return prev[1][k];
        
    }
};