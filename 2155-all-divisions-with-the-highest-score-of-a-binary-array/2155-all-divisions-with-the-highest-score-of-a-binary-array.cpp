class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        const int n = nums.size();
        int res = 0, zeroes = 0, ones = 0;
        unordered_map<int, vector<int>> m;
        for(int num : nums) if(num == 1) ones++;
        for(int i = 0; i <= n; ++i) {
            int score = zeroes + ones;
            res = max(res, score);
            m[score].emplace_back(i);
            if(i == n) continue;
            if(nums[i] == 0) zeroes += 1;
            else ones--;
            
        }
        return m[res];
    }
};