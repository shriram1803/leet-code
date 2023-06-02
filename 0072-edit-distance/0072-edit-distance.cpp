class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        
        vector<int> prev(s2 + 1), curr(s2 + 1);
        
        for(int i = 0; i <= s2; ++i) prev[i] = i;
        
        for(int m = 1; m <= s1; ++m) {
            curr[0] = m;
            for(int n = 1; n <= s2; ++n) {
                if(word1[m - 1] == word2[n - 1]) {
                    curr[n] = prev[n - 1];
                } else {
                    curr[n] = 1 + min({
                        prev[n], curr[n - 1], prev[n - 1]
                    });
                }
            }
            prev = curr;
        }
        
        
        return prev[s2];
    }
};