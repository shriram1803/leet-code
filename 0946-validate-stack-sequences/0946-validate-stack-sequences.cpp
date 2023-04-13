class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pop_index = 0, m = popped.size(), push_index;
        stack<int> st;
        for(push_index = 0; push_index < pushed.size(); ++push_index) {
            st.push(pushed[push_index]);
            while(st.size() and pop_index < m and popped[pop_index] == st.top())
                st.pop(), pop_index += 1;
        }
        return st.size() == 0;
    }
};