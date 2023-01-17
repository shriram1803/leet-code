class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> ones(n, 0), zeroes(n, 0);
        int prev = 0;
        for(int i = 0; i < n; ++i) {
            ones[i] += prev;
            prev += (s[i] == '1' ? 1 : 0);
        }
        prev = 0;
        for(int i = n - 1; i >= 0; --i) {
            zeroes[i] += prev;
            prev += (s[i] == '0' ? 1 : 0);
        }
        int res = INT_MAX;
        for(int i = 0; i < n; ++i) {
            res = min(res, ones[i] + zeroes[i]);
        }
        return res;
    }
};