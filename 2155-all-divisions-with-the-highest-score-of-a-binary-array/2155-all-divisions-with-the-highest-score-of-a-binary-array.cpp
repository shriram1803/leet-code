class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        const int n = nums.size();
        int res = 0, zeroes = 0, ones = 0;
        vector<int> v;
        for(int num : nums) if(num == 1) ones++;
        for(int i = 0; i <= n; ++i) {
            int score = zeroes + ones;
            if(score > res) {
                v.clear();
                v.emplace_back(i);
            } else if(score == res) {
                v.emplace_back(i);
            }
            res = max(res, score);
            if(i == n) continue;
            if(nums[i] == 0) zeroes += 1;
            else ones--;
            
        }
        return v;
    }
};