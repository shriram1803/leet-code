class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), res = 0, end = 0;
        auto cmp = [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; };
        sort(points.begin(), points.end(), cmp);
        for(int i = 0; i < n; ++i) {
            if(res == 0 or points[i][0] > end) {
                ++res;
                end = points[i][1];
            }
        }
        return res;
    }
};