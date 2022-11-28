class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        int largest = INT_MIN, smallest = INT_MAX, n = nums.size();
        for(int i = 0; i < n; ++i) {
            largest = nums[i], smallest = nums[i];
            for(int j = i + 1; j < n; ++j) {
                largest = max(largest, nums[j]);
                smallest = min(smallest, nums[j]);
                res += (largest - smallest);
            }
        }
        return res;
    }
};