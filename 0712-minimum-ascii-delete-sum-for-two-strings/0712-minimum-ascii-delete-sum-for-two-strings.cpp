class Solution {
public: 
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        
        vector<int> prev(n + 1), curr(n + 1);

        for(int j = 1; j <= n; ++j)
            prev[j] += prev[j - 1] + s2[j - 1];
        
        
        for(int i = 1; i <= m; ++i) {
            curr[0] += s1[i - 1];
            for(int j = 1; j <= n; ++j) {
                if(s1[i - 1] == s2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    curr[j] = min(s1[i - 1] + prev[j], s2[j - 1] + curr[j - 1]);
            }
            prev = curr;
        }
        
        
        return prev[n];
    }
};