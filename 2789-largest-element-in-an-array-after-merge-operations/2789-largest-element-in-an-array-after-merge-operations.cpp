class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        vector<long long> arr; //monotonic decreasing stack
        
        for(int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            if(!arr.empty() and arr.back() >= num)
                arr.back() += num;
            else
                arr.emplace_back(num);
        }
        
        return *max_element(arr.begin(), arr.end());
    }
};