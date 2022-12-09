class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int n = nums.size();
        int min_val = INT_MAX, min_ind = 0;
        
        long long total = accumulate(nums.begin(), nums.end(), (long long)0);
        long long curr = 0;
        long long forward, backward;
        
        for(int i = 0; i < n; ++i) {
            curr += nums[i];
            total -= nums[i];
            forward = curr / (i + 1);
            if(i != n - 1) backward = total / (n - i - 1);
            if(abs(forward - backward) < min_val) {
                min_val = abs(forward - backward);
                min_ind = i;
            }
            backward = 0; 
        }
        
        return min_ind;
    }
};