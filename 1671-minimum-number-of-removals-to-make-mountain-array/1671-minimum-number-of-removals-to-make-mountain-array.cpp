class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int res = 1e9;
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        //LIS (left[i] => the LIS till i provided i is included)
        vector<int> temp;
        for(int i = 0; i < n; ++i) {
            if(temp.empty() or temp.back() < nums[i]) {
                temp.emplace_back(nums[i]);
                left[i] = temp.size();
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
                left[i] = ind + 1;
            }
        }
        
        //LOGIC
        //For each index i we assume nums[i] to be the peak
        //So, to convert the array assuming nums[i] to be peak
        //we need to remove all the elements except it's LIS and Reverse LIS
        
        //Reverse LIS
        temp.clear();
        for(int i = n - 1; i >= 0; --i) {
            if(temp.empty() or temp.back() < nums[i]) {
                temp.emplace_back(nums[i]);
                right[i] = temp.size();
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
                right[i] = ind + 1;
            }
            
            if(left[i] == 1 or right[i] == 1) //check to only consider valid peak indexes
                continue;
            res = min(res, n - (left[i] + right[i] - 1));
            
        }
        
        
        return res;
    }
};