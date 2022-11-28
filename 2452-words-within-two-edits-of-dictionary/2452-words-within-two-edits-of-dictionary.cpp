class Solution {
public:
    bool solve(string a, string b, const int n) {
        for(int i = 0, cnt = 0; i < n; ++i) {
            if(a[i] != b[i]) cnt++;
            if(cnt > 2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        const int n = queries[0].size();
        vector<string> res;
        for(auto& query : queries) {
            for(auto& word : dictionary) {
                if(solve(query, word, n)) {
                    res.emplace_back(query);
                    break;
                }
            }
        }
        return res;
    }
};