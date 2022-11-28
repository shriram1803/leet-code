class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        const int n = nums.size();
        int max_score = 0, zeroes = 0, ones = accumulate(nums.begin(), nums.end(), 0);
        vector<int> v;
        for(int num : nums) if(num == 1) ones++;
        for(int i = 0; i <= n; ++i) {
            int score = zeroes + ones;
            if(score > max_score) {
                v.clear();
                v.emplace_back(i);
                max_score = score;
            } else if(score == max_score) {
                v.emplace_back(i);
            }
            if(i == n) continue;
            if(nums[i] == 0) zeroes += 1;
            else ones--;
            
        }
        return v;
    }
};