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
    int maxValue(vector<vector<int>>& events, int K) {
        int n = events.size();
        sort(events.begin(), events.end());
        
        vector<vector<int>> dp(n + 1, vector<int>(K + 1));
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int k = 1; k <= K; ++k) {
                int not_pick = dp[ind + 1][k];
        
                int next_ind = _upper_bound(events, ind + 1, events[ind][1]);
                int pick = events[ind][2] + dp[next_ind][k - 1];

                dp[ind][k] = max(pick, not_pick);
            }
        }
        
        return dp[0][K];
    }
};