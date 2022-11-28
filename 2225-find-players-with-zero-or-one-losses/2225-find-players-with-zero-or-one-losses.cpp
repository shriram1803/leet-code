class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> m;
        vector<vector<int>> res(2);
        for(auto& match : matches) {
            m[match[1]]++;
        }
        for(auto& match : matches) {
            if(m[match[0]] == 0) {
                res[0].emplace_back(match[0]);
                m[match[0]] = -1;
            }
            if(m[match[1]] == 1) {
                res[1].emplace_back(match[1]);
                m[match[1]] = -1;
            }
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};