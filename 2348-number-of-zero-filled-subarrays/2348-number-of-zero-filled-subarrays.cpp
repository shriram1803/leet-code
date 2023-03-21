class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        long long cont = 0;
        nums.emplace_back(1);
        for(int num : nums) {
            if(num == 0) {
                cont += 1;
            } else {
                res += cont * (cont + 1) / 2;
                cont = 0;
            }
        }
        return res;
    }
};