class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int counter = 1;
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] > counter)
                return counter;
            if(nums[i] == counter)
                counter += 1;
        }
        
        return counter;
    }
};