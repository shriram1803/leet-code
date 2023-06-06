class Solution {
public:
    bool check(string& big, string& small) {
        if(big.size() != small.size() + 1)
            return 0;
        int first = 0, second = 0;
        while(first < big.size()) {
            if(big[first] == small[second]) {
                ++first, ++second;
            } else {
                ++first;
            }
        }
        return first == big.size() and second == small.size();
    }
    static bool comp(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int res = 1, n = words.size();
        vector<int> dp(n, 1);
        
        sort(words.begin(), words.end(), comp);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(check(words[i], words[j]) and dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    res = max(res, dp[i]);
                }
            }
        }
        
        return res;
    }
};