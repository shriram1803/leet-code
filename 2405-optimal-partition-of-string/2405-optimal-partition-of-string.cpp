class Solution {
public:
    int partitionString(string s) {
        vector<int> freq(26, 0);
        int partitions = 1;
        for(auto ch : s) {
            if(freq[ch - 'a'] > 0) {
                partitions += 1;
                fill(freq.begin(), freq.end(), 0);
            }
            freq[ch - 'a'] += 1;
        }
        return partitions;
    }
};