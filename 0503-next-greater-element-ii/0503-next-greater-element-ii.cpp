class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> s, res(n, -1);
        
        for(int i = 0; i < 2 * n; ++i) {
            while(s.size() and nums[s.back()] < nums[i % n]) {
                res[s.back()] = nums[i % n];
                s.pop_back();
            }
            s.emplace_back(i % n);
        }

        return res;
    }
};