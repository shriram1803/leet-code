class Solution {
public:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
    int maxVowels(string s, int k) {
        int curr = 0;
        int res = 0;
        
        for(int i = 0; i < s.size(); ++i) {
            if(vowels.count(s[i]))
                ++curr;
            if(i >= k)
                curr -= vowels.count(s[i - k]);
            res = max(res, curr);
        }
        
        return res;
    }
};