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
        vector<int> dp(n + 1);
        sort(arr.begin(), arr.end());
        
        for(int ind = n - 1; ind >= 0; --ind) {
            
            int pick = m[arr[ind]] * arr[ind];
            if(ind == n - 1 or arr[ind + 1] != arr[ind] + 1) 
                pick += dp[ind + 1];
            else
                pick += dp[ind + 2];

            int not_pick = dp[ind + 1];
            
            dp[ind] = max(pick, not_pick);
        }
        
        return dp[0];
    }
};