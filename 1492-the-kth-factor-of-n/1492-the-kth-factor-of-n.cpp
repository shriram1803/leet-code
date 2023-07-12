class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i = 1; k > 0 and i <= n; ++i) {
            if(n % i == 0)
                k -= 1;
            if(k == 0)
                return i;
        }
        return -1;
    }
};