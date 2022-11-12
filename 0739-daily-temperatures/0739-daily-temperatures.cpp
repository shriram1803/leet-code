class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> s;
        for(int i = n - 1; i >= 0; --i){
            int cnt = 1;
            while(!s.empty() and s.top().first <= t[i]){
                cnt += s.top().second, s.pop();
            }
            if(s.empty()) {
                res[i] = 0;
                s.push({t[i], 1});
            } else {
                res[i] = cnt; 
                s.push({t[i], cnt});
            }
        }
        return res;
    }
};