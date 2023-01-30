class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1) return n;
        if(n == 2) return 1;
        int prevv = 0, prev = 1, pre = 1;
        for(int i = 3; i <= n; ++i) {
            int temp = pre + prev + prevv;
            prevv = prev, prev = pre, pre = temp;
        }
        return pre;
    }
};