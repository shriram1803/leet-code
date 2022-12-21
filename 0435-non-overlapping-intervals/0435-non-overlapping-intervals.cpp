class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end());
        int n = in.size();
        int cnt = 0;
        for(int i = 1; i < n; ++i) {
            if(in[i][0] >= in[i - 1][1]) {
                continue;
            } else {
                ++cnt;
                in[i][1] = min(in[i][1], in[i - 1][1]);
            }
        }
        return cnt;
    }
};