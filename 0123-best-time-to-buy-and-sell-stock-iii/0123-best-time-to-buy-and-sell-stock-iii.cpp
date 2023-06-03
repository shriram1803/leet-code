class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        const bool canBuy = 1;
        
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int rem = 1; rem <= 2; ++rem) {
                curr[canBuy][rem] = max(prev[canBuy][rem], -prices[ind] + prev[!canBuy][rem]);
                
                curr[!canBuy][rem] = max(prev[!canBuy][rem], prices[ind] + prev[canBuy][rem - 1]);
            }
            prev = curr;
        } 
        
        return prev[1][2];
    }
};