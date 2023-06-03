class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        
        for(int ind = 1; ind < prices.size(); ++ind) {
            if(prices[ind] > prices[ind - 1])
                max_profit += prices[ind] - prices[ind - 1];
        }
        
        return max_profit;
    }
};