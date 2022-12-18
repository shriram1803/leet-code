class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int, int>> s;
        int n = t.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i) {
            while(s.size() and s.top().first < t[i]) {
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({t[i], i});
        }
        return res;
    }
};