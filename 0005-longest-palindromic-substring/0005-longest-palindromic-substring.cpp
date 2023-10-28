class Solution {
public:
    void traverse(string& s, int left, int right, int& max_res, int& max_start, int n) {
        while(left >= 0 and right < n) {
            if(s[left] == s[right]) {
                if(right - left + 1 > max_res) {
                    max_res = right - left + 1;
                    max_start = left;
                }
                --left;
                ++right;
            } else {
                break;
            }
        }
    }
    string longestPalindrome(string s) {
        int max_res = 1;
        int max_start = 0;
        int n = s.size();
        
        for(int i = 1; i < n; ++i) {
            int left = i - 1, right = i + 1;
            traverse(s, left, right, max_res, max_start, n);
            if(s[i] != s[i - 1])
                continue;
            left = i - 1, right = i;
            traverse(s, left, right, max_res, max_start, n);            
        }
        
        return s.substr(max_start, max_res);
    }
};