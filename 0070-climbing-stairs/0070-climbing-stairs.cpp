class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev = 1, pre = 2, curr = -1;
        for(int i = 3; i <= n; ++i) {
            curr = pre + prev;
            prev = pre, pre = curr;
        }
        return pre;
    }
};