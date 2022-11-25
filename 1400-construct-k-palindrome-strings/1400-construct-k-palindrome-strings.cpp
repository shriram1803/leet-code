class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return false;
        int odd_cnt = 0;
        vector<int> v(26, 0);
        for(char ch : s) {
            v[ch - 'a']++;
        }
        for(int i = 0; i < 26; ++i) {
            if(v[i] % 2 == 1)
                odd_cnt++;
        }
        return (odd_cnt <= k);
    }
};