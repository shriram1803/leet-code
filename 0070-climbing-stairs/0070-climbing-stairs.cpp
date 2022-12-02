class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, pre = 1, curr = -1;
        for(int i = 2; i <= n; ++i) {
            curr = pre + prev;
            prev = pre, pre = curr;
        }
        return pre;
    }
};