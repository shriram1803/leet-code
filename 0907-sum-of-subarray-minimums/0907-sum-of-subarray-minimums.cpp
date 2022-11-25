class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int res = 0;
        const int MOD = 1e9 + 7;
        const int n = arr.size();
        stack<int> s, s1;
        vector<int> nxt(n, 0), pre(n, 0);
        
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and arr[s.top()] > arr[i]) {
                s.pop();
            }
            if(s.empty()) {
                pre[i] = i + 1;
            } else 
                pre[i] = i - s.top();
            s.push(i);
        }
    
        for(int i = n - 1; i >= 0; --i) {
            while(!s1.empty() and arr[s1.top()] >= arr[i]) {
                s1.pop();
            }
            if(s1.empty()) {
                nxt[i] = n - i;
            } else 
                nxt[i] = s1.top() - i;
            s1.push(i);
        }
        
        for(int i = 0; i < n; ++i) {
            long long prod = (nxt[i]*pre[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res % MOD;
    }
};