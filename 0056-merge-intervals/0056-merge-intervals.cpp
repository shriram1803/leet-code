class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.emplace_back(intervals[0]);
        for(int i = 1; i < n; ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int back_end = res.back()[1];
            if(back_end >= start) {
                if(end > back_end) 
                    res.back()[1] = end;
            } else {
                res.emplace_back(intervals[i]);
            }
        }
        return res;
    }
};