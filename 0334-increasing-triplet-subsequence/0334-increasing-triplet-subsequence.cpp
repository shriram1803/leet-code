class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> mono;
        int ind;
        // LIS Algorithm
        for(int num : nums) {
            if(mono.empty() or mono.back() < num) {
                mono.emplace_back(num);
                if(mono.size() == 3)
                    return 1;
                continue;
            }
            ind = lower_bound(mono.begin(), mono.end(), num) - mono.begin();
            mono[ind] = num;
        }
        return 0;
    }
};