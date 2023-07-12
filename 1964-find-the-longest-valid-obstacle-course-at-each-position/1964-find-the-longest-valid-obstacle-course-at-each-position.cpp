class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> monotonic;
        vector<int> res;
        
        for(int obs : obstacles) {
            if(monotonic.empty() or monotonic.back() <= obs) {
                monotonic.emplace_back(obs);
                res.emplace_back(monotonic.size());
            } else {
                int ind = upper_bound(monotonic.begin(), monotonic.end(), obs) - monotonic.begin();
                res.emplace_back(ind + 1);
                monotonic[ind] = obs;
            }
        }
        
        return res;
    }
};