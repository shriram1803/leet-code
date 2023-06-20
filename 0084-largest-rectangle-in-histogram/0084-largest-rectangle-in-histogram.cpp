class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s, s1;
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if(!s.empty())
                left[i] = s.top() + 1;
            else
                left[i] = 0;
            s.push(i);
        }
        for(int i = n - 1; i >= 0; --i) {
            while(!s1.empty() and heights[s1.top()] >= heights[i]) {
                s1.pop();
            }
            if(!s1.empty())
                right[i] = s1.top() - 1;
            else
                right[i] = n - 1;
            s1.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res = max(res, heights[i] * (right[i] - left[i] + 1));
        }
        return res;
    }
};