class Solution {
public:
    int f(int ind, const int n, vector<int>& arr, unordered_map<int, int>& m, vector<int>& dp) {
        if(ind == n)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int pick = m[arr[ind]] * arr[ind];
        if(ind == n - 1 or arr[ind + 1] != arr[ind] + 1) 
            pick += f(ind + 1, n, arr, m, dp);
        else
            pick += f(ind + 2, n, arr, m, dp);
        
        int not_pick = f(ind + 1, n, arr, m, dp);
        
        return dp[ind] = max(pick, not_pick);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> arr;
        
        for(int num : nums) {
            m[num] += 1;
            if(m[num] == 1)
                arr.emplace_back(num);
        }
        
        int n = arr.size();
        vector<int> dp(n, - 1);
        sort(arr.begin(), arr.end());
        
        return f(0, n, arr, m, dp);
    }
};