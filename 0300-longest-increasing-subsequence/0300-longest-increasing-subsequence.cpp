class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        int res = 0;
        
        for(int num : nums) {
            if(arr.empty() or arr.back() < num) {
                arr.emplace_back(num);
                res += 1;
                continue;
            }
            int ind = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
            arr[ind] = num;
        }
        
        return res;
    }
};