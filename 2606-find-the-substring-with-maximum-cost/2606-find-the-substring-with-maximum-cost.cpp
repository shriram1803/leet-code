class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> value(26);
        for(int i = 0; i < 26; ++i) 
            value[i] = i + 1;
        for(int i = 0; i < chars.size(); ++i) {
            value[chars[i] - 'a'] = vals[i];
        }
        int maximum = 0, curr = 0;
        for(auto ch : s) {
            curr += value[ch - 'a'];
            maximum = max(maximum, curr);
            if(curr < 0)
                curr = 0;
        }
        return maximum;
    }
};