class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 1), right(n, 1);
        stack<int> s, s1;
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and heights[s.top()] >= heights[i]) {
                left[i] += left[s.top()];
                s.pop();
            }
            s.push(i);
        }
        for(int i = n - 1; i >= 0; --i) {
            while(!s1.empty() and heights[s1.top()] >= heights[i]) {
                right[i] += right[s1.top()];
                s1.pop();
            }
            s1.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res = max(res, heights[i] * (left[i] + right[i] - 1));
        }
        return res;
    }
};