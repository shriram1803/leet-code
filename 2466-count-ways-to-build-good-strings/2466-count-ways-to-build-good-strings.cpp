class Solution {
public:
    const int mod = (int)(1e9 + 7);
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high + 1);
        
        for(int curr = high; curr >= 0; --curr) {
        
            dp[curr] = (
                (curr + one <= high ? dp[curr + one] : 0) % mod 
                + 
                (curr + zero <= high ? dp[curr + zero] : 0) % mod
            ) % mod;
            
            if(curr >= low)
                dp[curr] += 1;
        }
        
        return dp[0];
    }
};