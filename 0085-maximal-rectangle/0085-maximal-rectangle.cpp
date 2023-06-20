class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        stack<int> s;
        for(int i = 0; i <= n; ++i) {
            while(!s.empty() and (i == n or heights[s.top()] >= heights[i])) {
                int height = heights[s.top()];
                s.pop();
                int width;
                if(!s.empty())
                    width = i - s.top() - 1;
                else
                    width = i;
                res = max(res, height * width);
            }
            s.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    dp[j] = 1 + dp[j];
                } else {
                    dp[j] = 0;
                }
            }
            ans = max(ans, largestRectangleArea(dp));
        }
        return ans;
    }
};