class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        //LIS (left[i] => the LIS till i provided i is included)
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i])
                    left[i] = max(left[i], 1 + left[j]);
            }
        }
        
        //Reverse LIS
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j > i; --j) {
                if(nums[j] < nums[i])
                    right[i] = max(right[i], 1 + right[j]);
            }
        }
        
        //LOGIC
        //For each index i we assume nums[i] to be the peak
        //So, to convert the array assuming nums[i] to be peak
        //we need to remove all the elements except it's LIS and Reverse LIS
        int res = 1e9;
        bool start = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(left[i] == 0 or right[i] == 0) //check to only consider valid peak indexes
                continue;
            res = min(res, n - (left[i] + right[i] + 1));
        }
        
        return res;
    }
};