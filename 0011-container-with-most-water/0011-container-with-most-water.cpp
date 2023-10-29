class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = -1e9;
        
        while(left < right) {
            res = max(res, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]) {
                ++left;
            } else if(height[left] > height[right]) {
                --right;
            } else {
                ++left;
                --right;
            }
        }
        
        return res;
    }
};