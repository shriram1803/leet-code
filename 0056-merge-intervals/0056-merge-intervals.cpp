class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res = { intervals[0] };
        
        for(auto& interval : intervals) {
            if(res.back()[1] >= interval[0])
                res.back()[1] = max(res.back()[1], interval[1]);
            else
                res.emplace_back(interval);
        }
        
        return res;
        
    }
};