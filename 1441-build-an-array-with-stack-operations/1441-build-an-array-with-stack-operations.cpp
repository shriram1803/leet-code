class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        stack<int> st;
        
        for(int i = 1, j = 0; j < target.size() and i <= n; ++i) {
            st.push(i);
            res.emplace_back("Push");
            if(st.top() < target[j]) {
                res.emplace_back("Pop");
                st.pop();
            } else {
                ++j;
            }
        }
        
        return res;
    }
};