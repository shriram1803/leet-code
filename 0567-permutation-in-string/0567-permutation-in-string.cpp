class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        vector<int> v1(26, 0), v2(26, 0);
        for(char ch : s1) {
            ++v1[ch - 'a'];
        }
        for(int i = 0; i < m; ++i) {
            ++v2[s2[i] - 'a'];
            if(i >= n) {
                --v2[s2[i - n] - 'a'];
            }
            if(v1 == v2)
                    return true;
        }
        return false;
    }
};