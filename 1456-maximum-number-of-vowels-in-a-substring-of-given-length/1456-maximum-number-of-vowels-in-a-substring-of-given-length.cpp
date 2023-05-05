class Solution {
public:
    int maxVowels(string s, int k) {
        int vow_cnt = 0;
        int max_vow_cnt = 0;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < s.size(); ++i) {
            if(i >= k and vowels.count(s[i - k]))
                vow_cnt -= 1;
            if(vowels.count(s[i]))
                vow_cnt += 1;
            max_vow_cnt = max(max_vow_cnt, vow_cnt);
        }
        return max_vow_cnt;
    }
};