class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        const int n = nums.size();
        int min_val = INT_MAX, min_ind = 0;
        vector<long long> forward(n, 0), backward(n, 0);
        
        for(long long i = 0, cumulative = 0; i < n; ++i) {
            cumulative += nums[i];
            forward[i] = cumulative / (i + 1);
        }
        
        for(long long i = n - 1, cumulative = 0; i >= 0; --i) {
            if(i < n - 1) backward[i] = cumulative / (n - (i + 1));
            cumulative += nums[i];
        }
        
        for(int i = 0; i < n; ++i) {
            if(abs(forward[i] - backward[i]) < min_val) {
                min_val = abs(forward[i] - backward[i]);
                min_ind = i;
            }
        }
        
        return min_ind;
    }
};