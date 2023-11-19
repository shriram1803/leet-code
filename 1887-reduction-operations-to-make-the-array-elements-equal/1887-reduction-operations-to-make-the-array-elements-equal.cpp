class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int res = 0;
        
        sort(nums.begin(), nums.end(), greater());
        for(int i = 1; i < nums.size(); ++i)
            if(nums[i] != nums[i - 1])
                res += i;
        
        return res;
    }
};