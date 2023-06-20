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
};