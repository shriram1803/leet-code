class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        short freq[2001] = {0};
        for(int num : arr) ++freq[num + 1000];
        sort(freq, freq + 2001);
        for(int i = 1; i < 2001; ++i) {
            if(freq[i] and freq[i] == freq[i - 1]) return false;
        }
        return true;
    }
};