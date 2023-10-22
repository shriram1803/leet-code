class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        /*  
        Solved Using MAX Sum sliding window approach using queue
        */
        
        int res = nums[0];
        int n = nums.size();     
        
        deque<pair<int, int>> dq;
        
        dq.push_back({nums[0], 0});
        
        for(int j = 1; j < n; ++j) {
            while (!dq.empty() and dq.front().second < j - k) 
                dq.pop_front();
            
            int pre_max = nums[j] + dq.front().first;
            int cur_max = max(nums[j], pre_max);
        
            res = max(res, cur_max);
            
            while (!dq.empty() and dq.back().first <= cur_max)
                dq.pop_back();
            
            dq.push_back({cur_max, j});
        }
        
        return res;
    }
};