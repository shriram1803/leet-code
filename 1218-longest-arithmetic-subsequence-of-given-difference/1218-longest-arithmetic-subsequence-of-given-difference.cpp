class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int maxi = 1;
        unordered_map<int, int> m;
        
        for(int num : arr) {
            if(m.count(num - difference))
                m[num] = 1 + m[num - difference];
            else
                m[num] = 1;
            maxi = max(maxi, m[num]);
        }
        
        return maxi;
    }
};