class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = -1, next_max = -1;
        for(int num : nums) {
            if(num >= maxx) {
                next_max = maxx;
                maxx = num;
            } else if(num < maxx and num > next_max) {
                next_max = num;
            }
        }
        return (next_max - 1) * (maxx - 1);
    } 
};