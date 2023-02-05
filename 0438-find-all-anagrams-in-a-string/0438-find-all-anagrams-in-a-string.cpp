class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if(n < m) return {};
        vector<int> P(26, 0), S(26, 0), res;
        for(auto ch : p) {
            ++P[ch - 'a']; 
        }
        for(int i = 0; i < n; ++i) {
            ++S[s[i] - 'a'];
            if(i >= m) {
                --S[s[i - m] - 'a'];
            }
            if(P == S) {
                res.emplace_back(i - m + 1);
            }
        }
        return res;
    }
};