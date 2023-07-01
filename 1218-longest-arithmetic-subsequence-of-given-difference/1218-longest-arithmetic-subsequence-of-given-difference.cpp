class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n = arr.size();
        
        unordered_map<int, int> m;
        int maxi = 1;
        
        
        for(int num : arr) {
            if(m.count(num - d)) {
                m[num] = max(m[num], 1 + m[num - d]);
                maxi = max(maxi, m[num]);
            } else {
                m[num] = 1;
            }
        }
        
        return maxi;
    }
};