class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), res = n;
        sort(points.begin(), points.end());
        for(int i = 1; i < n; ++i) {
            if(points[i][0] <= points[i - 1][1]) {
                points[i][0] = max(points[i][0], points[i - 1][0]);
                points[i][1] = min(points[i][1], points[i - 1][1]);
                --res;
            }
        }
        return res;
    }
};