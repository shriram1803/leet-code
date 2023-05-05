class Solution {
public:
    int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
    int maxVowels(string s, int k) {
        int vow_cnt = 0;
        int max_vow_cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(i >= k)
                vow_cnt -= vowels[s[i - k] - 'a'];
            vow_cnt += vowels[s[i] - 'a'];
            max_vow_cnt = max(max_vow_cnt, vow_cnt);
        }
        return max_vow_cnt;
    }
};