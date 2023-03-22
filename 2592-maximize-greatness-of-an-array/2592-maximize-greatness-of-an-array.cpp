class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > nums[cnt]) {
                cnt += 1;
            }
        }
        return cnt;
    }
};