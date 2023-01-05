class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> v;
        sort(points.begin(), points.end());
        v.emplace_back(points[0]);
        for(int i = 1; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            if(x <= v.back()[1]) {
                v.back()[0] = max(v.back()[0], x);
                v.back()[1] = min(v.back()[1], y);
            } else {
                v.emplace_back(points[i]);
            }
        }
        return v.size();
    }
};