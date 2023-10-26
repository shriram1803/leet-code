class Solution {
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        long long res = 0;
        unordered_map<int, long long> dp;
        sort(arr.begin(), arr.end());
        
        for(int v : arr)
            dp[v] += 1;        
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(arr[j] > sqrt(arr[i]))
                    break;
                if(arr[i] % arr[j] == 0 and dp.find(arr[i] / arr[j]) != dp.end()) {
                    long long tmp = dp[arr[j]] * dp[arr[i] / arr[j]];
                    if(arr[i] / arr[j] == arr[j]) {
                        dp[arr[i]] = (dp[arr[i]] + tmp) % mod;
                    } else {
                        dp[arr[i]] = (dp[arr[i]] + 2 * tmp) % mod;
                    }
                }
            }
        }
        
        for(auto& it : dp) {
            res = (res + it.second) % mod;
        }
        
        return res;
    }
};