class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        for(int num : nums) {
            if(m[num]) {
                ++res;
                --m[num];
            } else {
                ++m[k - num];
            }
        }
        return res;
    }
};