class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";
        for(auto& ch : s){
            if(ch == ' ') {
                if(str != "") st.push(str), str = "";
            } else {
                str += ch;
            }
        }
        if(str != "") st.push(str), str = "";
        while(1) {
            str += st.top(), st.pop();
            if(st.empty()) break;
            else str += " ";
        }
        return str;
    }
};