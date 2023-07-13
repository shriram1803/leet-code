class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        
        vector<int> curr(n + 1), prev(n + 1);
        
        
        for(int front = n - 1; front >= 0; --front) {
            curr[front] = 1;
            for(int back = front + 1; back < n; ++back) {
                if(s[front] == s[back])
                    curr[back] = 2 + prev[back - 1];
                else
                    curr[back] = max(prev[back], curr[back - 1]);
            }
            prev = curr;
        }
        
        return prev[n - 1];
    }
};