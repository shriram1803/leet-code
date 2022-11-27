class Solution {
public:
    int solve(string s, string t, int n, int m)
    {
        int j = 0;
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == t[j]) {
                j++;
            }
        }
        
        return j;
    }
    int appendCharacters(string s, string t) {
        int val = solve(s, t, s.size(), t.size());
        return (t.size() - val);
    }
};