class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> res(n);
        
        for(int i = temperatures.size() - 1; i >= 0; --i) {
            int temp = temperatures[i];
            while(!s.empty() and temperatures[s.top()] <= temperatures[i]) s.pop();
            if(!s.empty()) {
                res[i] = s.top() - i;
            }
            s.push(i);
        }
        
        return res;
    }
};