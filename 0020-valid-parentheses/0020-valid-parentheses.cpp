class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch : s) {
            if(ch == '(' or ch == '{' or ch == '[') {
                st.push(ch);
            } else {
                if(st.empty())
                    return false;
                if(ch == ')') {
                    if(st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if(ch == '}') {
                    if(st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    if(st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }                
                } 
            }
        }
        return st.size() == 0;
    }
};