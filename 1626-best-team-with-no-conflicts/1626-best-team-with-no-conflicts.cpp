class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size(), res;
        vector<pair<int, int>> v;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i) {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for(int i = 0; i < n; ++i) {
            dp[i] = v[i].second;
            for(int j = 0; j < i; ++j) {
                if(v[i].second > v[j].second) continue;
                dp[i] = max(dp[i], v[i].second + dp[j]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};