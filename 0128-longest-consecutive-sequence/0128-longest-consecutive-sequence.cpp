class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int longest = 0, curr = 0, prev = INT_MIN;
        
        set<int> s(nums.begin(), nums.end());
        
        for(int val : s) {
            if(val == prev + 1) curr++;
            else curr = 1;
            prev = val;
            longest = max(longest, curr);
        }
        
        return longest;
    }
};