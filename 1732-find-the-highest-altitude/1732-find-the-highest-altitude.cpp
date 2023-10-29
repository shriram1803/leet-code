class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int ps = 0;
        for(int i = 0; i < gain.size(); ++i) {
            ps += gain[i];
            res = max(res, ps);
        }
        return res;
    }
};