class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        //LIS (left[i] => the LIS till i provided i is included)
        vector<int> temp{nums[0]};
        for(int i = 1; i < n; ++i) {
            if(temp.back() < nums[i]) {
                temp.emplace_back(nums[i]);
                left[i] = temp.size();
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
                left[i] = ind + 1;
            }
        }
        
        //Reverse LIS
        vector<int> tmp{nums[n - 1]};
        for(int i = n - 2; i >= 0; --i) {
            if(tmp.back() < nums[i]) {
                tmp.emplace_back(nums[i]);
                right[i] = tmp.size();
            } else {
                int ind = lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin();
                tmp[ind] = nums[i];
                right[i] = ind + 1;
            }
        }
        
        //LOGIC
        //For each index i we assume nums[i] to be the peak
        //So, to convert the array assuming nums[i] to be peak
        //we need to remove all the elements except it's LIS and Reverse LIS
        int res = 1e9;
        for(int i = 1; i < n - 1; ++i) {
            if(left[i] == 1 or right[i] == 1) //check to only consider valid peak indexes
                continue;
            res = min(res, n - (left[i] + right[i] - 1));
        }
        
        return res;
    }
};