class Solution {
public:
    int longestContinuousSubstring(string s) {
        int longest = 1, curr = 1, n = s.size();
        for(int i = 1; i < n; ++i) {
            if(s[i] == s[i - 1] + 1) curr++;
            else curr = 1;
            longest = max(longest, curr);
        }
        return longest;
    }
};