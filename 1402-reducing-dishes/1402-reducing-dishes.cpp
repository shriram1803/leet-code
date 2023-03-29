class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int curr_sum = 0;
        int curr_sat = 0;
        int res = 0;
        int n = s.size();
        sort(s.begin(), s.end());
        for(int i = n - 1; i >= 0; --i) {
            curr_sum += s[i];
            curr_sat += curr_sum;
            res = max(res, curr_sat);
        }
        return res;        
    }
};