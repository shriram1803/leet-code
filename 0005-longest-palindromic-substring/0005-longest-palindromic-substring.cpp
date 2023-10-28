class Solution {
public:
    bool isPal(string& s, int j, int i) {
        bool res = true;
        while(res and i < j) {
            if(s[i] != s[j]) 
                res = false;
            ++i;
            --j;
        }
        return res;
    }
    string longestPalindrome(string s) {
        string res = "";
        int max_res = 1;
        int n = s.size();
        res += s[0];
        
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(j - i + 1 > max_res && isPal(s, j, i)) {
                    max_res = j - i + 1;
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        
        return res;
    }
};