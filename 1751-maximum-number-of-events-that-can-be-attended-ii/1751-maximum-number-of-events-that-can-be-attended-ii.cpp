class Solution {
public:
    int _upper_bound(vector<vector<int>>& events, int start, int targ) {
        int end = events.size() - 1;
        int mid;
        
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(events[mid][0] > targ) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
    int f(int ind, const int n, const int k, vector<vector<int>>& events, vector<vector<int>>& dp) {
        if(ind == n or k == 0)
            return 0;
        
        if(dp[ind][k] != -1)
            return dp[ind][k];
        
        int not_pick = f(ind + 1, n, k, events, dp);
        
        int next_ind = _upper_bound(events, ind + 1, events[ind][1]);
        int pick = events[ind][2] + f(next_ind, n, k - 1, events, dp);
        
        return dp[ind][k] = max(pick, not_pick);
    }
    int maxValue(vector<vector<int>>& events, int K) {
        int n = events.size();
        sort(events.begin(), events.end());
        
        vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        
        return f(0, n, K, events, dp);
    }
};