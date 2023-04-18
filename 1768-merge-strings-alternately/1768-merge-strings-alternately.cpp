class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;
        string res = "";
        while(i < m and j < n) {
            res += word1[i++];
            res += word2[j++];
        }
        while(i < m) {
            res += word1[i++];
        }
        while(j < n) {
            res += word2[j++];
        }
        return res;
    }
};