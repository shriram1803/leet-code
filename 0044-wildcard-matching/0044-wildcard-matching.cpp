class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        vector<bool> prev(n + 1, 0), curr(n + 1);
        
        prev[0] = 1;
        for(int i = 1; i <= n; ++i) {
            if(p[i - 1] != '*')
                break;
            prev[i] = 1;
        }
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {                    
                if(s[i - 1] == p[j - 1] or p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if(p[j - 1] == '*')
                    curr[j] = prev[j] | curr[j - 1];
                else
                    curr[j] = 0;
            }
            prev = curr;
        }
        
        return prev[n];
    }
};