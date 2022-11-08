class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = s.size() - 1; i >= 0; --i){
            if(st.size() and (st.top() == (s[i] + 32) or st.top() == (s[i] - 32))){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};