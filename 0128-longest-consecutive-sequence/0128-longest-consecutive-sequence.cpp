class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int longest = 0;
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        for(int val : s) {
            if(s.count(val - 1)) continue;
            int local = 1;
            while(s.count(++val)) local++;
            longest = max(longest, local);
        }
        
        return longest;
    }
};