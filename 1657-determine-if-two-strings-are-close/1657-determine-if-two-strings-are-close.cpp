class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> freq1(26, 0), freq2(26, 0), s1(26, 0), s2(26, 0);
        for(int i = 0; i < word1.size(); ++i) {
            freq1[word1[i] - 'a']++;
            s1[word1[i] - 'a'] = 1;
            freq2[word2[i] - 'a']++;
            s2[word2[i] - 'a'] = 1;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2 and s1 == s2;
    }
};