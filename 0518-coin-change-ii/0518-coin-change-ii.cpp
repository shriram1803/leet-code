class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<int> prev(amount + 1), curr(amount + 1);
        
        for(int amt = 0; amt <= amount; amt += coins[0]) 
            prev[amt] = 1;
        
        for(int ind = 1; ind < n; ++ind) {
            for(int amt = 0; amt <= amount; ++amt) {
                
                //Not pick case
                int res = prev[amt];

                //Pick case
                if(amt >= coins[ind])
                    res += curr[amt - coins[ind]];

                curr[amt] = res;
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};