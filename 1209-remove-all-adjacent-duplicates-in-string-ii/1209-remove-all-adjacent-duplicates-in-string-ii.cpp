class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>> st;
        st.push({'#', 0});
        for(int i = s.size() - 1; i >= 0; --i){
            if(st.top().first != s[i]){
                st.push({s[i], 1});
            } else if(++st.top().second == k) {
                st.pop();
            }
        }
        string res;
        while(!st.empty()) {
            res.append(st.top().second, st.top().first), st.pop();
        }
        return res;
    }
};