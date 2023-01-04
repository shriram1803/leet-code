class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res=  0;
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0], right[n - 1] = height[n - 1];
        for(int i = 1; i < n; ++i) {
            left[i] = max(height[i], left[i - 1]);
        }
        for(int i = n - 2; i >= 0; --i) {
            right[i] = max(height[i], right[i + 1]);
        }
        for(int i = 0; i < n; ++i) {
            int val = min(left[i], right[i]) - height[i];
            res += val > 0 ? val : 0;
        }
        return res;
    }
};