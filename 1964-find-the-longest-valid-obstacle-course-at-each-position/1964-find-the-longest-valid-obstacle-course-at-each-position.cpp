class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> monotonic = {obstacles[0]};
        vector<int> res(n);
        res[0] = 1;
        
        
        //Modified LIS Template
        for(int i = 1; i < n; ++i) {
            if(monotonic.back() <= obstacles[i]) {
                monotonic.emplace_back(obstacles[i]);
                res[i] = monotonic.size();
            } else {
                int ind = upper_bound(monotonic.begin(), monotonic.end(), obstacles[i]) - monotonic.begin();
                res[i] = ind + 1;
                monotonic[ind] = obstacles[i];
            }
        }
        
        return res;
    }
};