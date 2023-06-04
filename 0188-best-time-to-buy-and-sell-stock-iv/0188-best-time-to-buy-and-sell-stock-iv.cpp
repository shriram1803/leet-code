class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector<int> prev(2*k + 1, 0), curr(2*k + 1, 0);
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int tran = 2*k - 1; tran >= 0; --tran) {
                if(tran % 2) {
                    curr[tran] = max(prev[tran], prices[ind] + prev[tran + 1]);                
                } else {
                    curr[tran] = max(prev[tran], -prices[ind] + prev[tran + 1]);
                }
            }
            prev = curr;
        } 
        
        return prev[0];
        
    }
};