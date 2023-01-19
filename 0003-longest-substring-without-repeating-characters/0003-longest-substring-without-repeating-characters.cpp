class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a = 0, b = 0, n = s.size();
        int res = 0;
        
        unordered_map<char, int> v;
        for(b = 0; b < n; ++b) {
            if(v[s[b]] == 0) {
                ++v[s[b]];
                res = max(res, b - a + 1);
            } else {
                while(a < n and v[s[b]] > 0) --v[s[a]], ++a;
                ++v[s[b]];
            }
        }
        
        return res;
    }
};