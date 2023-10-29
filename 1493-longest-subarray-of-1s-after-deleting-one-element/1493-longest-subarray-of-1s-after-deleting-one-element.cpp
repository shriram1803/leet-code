class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> left(n), right(n);
        int cont = 0;
        
        for(int i = 0; i < n; ++i) {
            left[i] = cont;
            if(nums[i] == 0) {
                cont = 0;
            } else {
                cont += 1;
            }
        }
        
        for(int i = n - 1, cont = 0; i >= 0; --i) {
            right[i] = cont;
            if(nums[i] == 0) {
                cont = 0;
            } else {
                cont += 1;
            }
        }
        
        for(int i = 0; i < n; ++i) {
            res = max(res, left[i] + right[i]);
        }
        
        return res;
    }
};