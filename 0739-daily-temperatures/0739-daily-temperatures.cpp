class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> res(n, 0);
        stack<int> s;
        for(int i = n - 1; i >= 0; --i){
            while(!s.empty() and t[s.top()] <= t[i]){
                s.pop();
            }
            if(!s.empty()) {
                res[i] = s.top() - i; 
            }
            s.push(i);
        }
        return res;
    }
};