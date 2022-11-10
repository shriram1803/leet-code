class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>> st;
        for(int i = s.size() - 1; i >= 0; --i){
            if(st.size() and st.top().first == s[i]){
                if(st.top().second == k - 1)
                    st.pop();
                else{
                    int val = (st.top().second) + 1;
                    st.pop();
                    st.push({s[i], val});
                }
            } else {
                st.push({s[i], 1});
            }
        }
        string res = "";
        while(!st.empty()) {
            int t = st.top().second;
            char ch = st.top().first;
            while(t--) {
                res += ch;
            }
            st.pop();
        }
        return res;
    }
};