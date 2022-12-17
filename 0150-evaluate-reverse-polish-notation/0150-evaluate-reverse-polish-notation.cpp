class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long long> st;
        long long val1, val2;
        for(string token : tokens) {
            if(token == "+" or token == "*" or token == "/" or token == "-") {
                val2 = st.back(), st.pop_back();
                val1 = st.back();
                if(token == "+") val1 += val2;
                else if(token == "-") val1 -= val2;
                else if(token == "*") val1 *= val2;
                else val1 /= val2;
                st.back() = val1;
            } else {
                st.emplace_back(stoi(token));
            }
        }
        return st.back();
    }
};