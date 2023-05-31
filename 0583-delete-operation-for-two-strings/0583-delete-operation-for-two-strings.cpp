class Solution {
public:
    int lis(string& text1, string& text2) {
        int m = text1.size(), n = text2.size();
        vector<int> prev(n + 1, 0), curr(n + 1);
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        
        return prev[n];
    }
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * lis(word1, word2);
    }
};