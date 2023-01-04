class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size(), res = INT_MIN;
        for(int i = 0; i < n; ++i) {
            int curr = 0;
            for(int j = i, num = 1; j < n; ++j, ++num) {
                curr += v[j]*num;
            }
            res = max(res, curr);
        }
        return res > 0 ? res : 0;
    }
};