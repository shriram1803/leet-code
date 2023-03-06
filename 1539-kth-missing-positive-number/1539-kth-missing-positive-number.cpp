class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(arr.begin(), arr.end());
        for(int i = 1; ; ++i) {
            if(s.count(i) == 0) {
                k -= 1;
            }
            if(k == 0) {
                return i;
            }
        }
        return -1;
    }
};