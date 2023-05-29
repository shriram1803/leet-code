class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        
        for(int i = 0; i <= amount; i += coins[0]) {
            prev[i] = 1;
        }
        
        for(int ind = 1; ind < n; ++ind) {
            for(int amt = 0; amt <= amount; ++amt) {
                int not_pick = prev[amt];
                int pick = 0;
                if(amt >= coins[ind])
                    pick += curr[amt - coins[ind]];
                curr[amt] = not_pick + pick;
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};