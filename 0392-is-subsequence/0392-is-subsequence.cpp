class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        
        while(i >= 0 and j >= 0) {
            if(s[i] == t[j])
                --i;
            --j;
        }
        
        return i < 0;
    }
};