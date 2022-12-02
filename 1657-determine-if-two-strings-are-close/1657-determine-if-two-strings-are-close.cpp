class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> freq1(26, 0), freq2(26, 0);
        unordered_map<int, int> m;
        for(int i = 0; i < word1.size(); ++i) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }
        for(int i = 0; i < 26; ++i) {
            if(freq1[i] == 0 and freq2[i] == 0) continue;
            if(freq1[i] == 0 or freq2[i] == 0) return false;
            m[freq1[i]]++;
            m[freq2[i]]--;
        }
        for(auto [val, cnt] : m) if(cnt != 0) return false;
        return true;
    }
};