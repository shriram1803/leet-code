class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> res, dp(n + 1, INT_MAX);
        for(int obstacle : obstacles) {
            int ind = upper_bound(dp.begin(), dp.end(), obstacle) - dp.begin();
            res.emplace_back(ind + 1);
            dp[ind] = min(dp[ind], obstacle);
        }
        return res;
    }
};