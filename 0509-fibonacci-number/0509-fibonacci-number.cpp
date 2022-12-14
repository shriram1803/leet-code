class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        int prev = 0, pre = 1, curr = -1;
        for(int i = 2; i <= n; ++i) {
            curr = pre + prev;
            prev = pre, pre = curr;
        }
        return pre;
    }
};