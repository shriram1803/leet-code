class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        const bool canBuy = 1, cannotBuy = 0;
        
        vector<int> prev(2, 0), curr(2, 0);
        
        for(int ind = n - 1; ind >= 0; --ind) {
            curr[canBuy] = max(prev[canBuy], -prices[ind] +  prev[cannotBuy]);
            
            // Similar to Stock II - Just subtracted the transaction fee 
            curr[cannotBuy] = max(prev[cannotBuy], prices[ind] - fee +  prev[canBuy]);
            
            prev = curr;
        }
        
        return prev[1];
    }
};