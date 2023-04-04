class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int partitions = 1;
        for(auto ch : s) {
            if(st.count(ch)) {
                st.clear();
                partitions += 1;
            }
            st.insert(ch);
        }
        return partitions;
    }
};