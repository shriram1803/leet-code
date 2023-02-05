class Solution {
public:
    unordered_set<char> vow{'a', 'e', 'i', 'o', 'u'};
    int check(string& s) {
        if(vow.count(s[0]) and vow.count(s.back()))
            return 1;
        return 0;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> pf(n, 0), res(m, 0);
        pf[0] = check(words[0]);
        for(int i = 1; i < n; ++i) {
            pf[i] += pf[i - 1] + check(words[i]);
        }
        for(int i = 0; i < m; ++i) {
            if(queries[i][0] == 0) {
                res[i] = pf[queries[i][1]];
            } else {
                res[i] = pf[queries[i][1]] - pf[queries[i][0] - 1];
            }
        }
        return res;
    }
};