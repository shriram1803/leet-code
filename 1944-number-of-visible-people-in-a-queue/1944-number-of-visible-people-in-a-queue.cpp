class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        stack<int> st;
        for(int i = n - 1; i >= 0; --i) {
            int cnt = 0;
            while(!st.empty() and st.top() < heights[i]) ++cnt, st.pop();
            if(!st.empty()) ++cnt;
            res[i] = cnt;
            st.push(heights[i]);
        }
        return res;
    }
};