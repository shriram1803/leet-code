class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> arr;
        
        for(int num : nums) {
            m[num] += 1;
            if(m[num] == 1)
                arr.emplace_back(num);
        }
        
        int n = arr.size();
        vector<int> dp(2);
        sort(arr.begin(), arr.end());
        
        for(int ind = n - 1; ind >= 0; --ind) {
            
            int pick = m[arr[ind]] * arr[ind];
            if(ind == n - 1 or arr[ind + 1] != arr[ind] + 1) 
                pick += dp[0];
            else
                pick += dp[1];

            int not_pick = dp[0];
            
            dp[1] = dp[0];
            dp[0] = max(pick, not_pick);
        }
        
        return dp[0];
    }
};