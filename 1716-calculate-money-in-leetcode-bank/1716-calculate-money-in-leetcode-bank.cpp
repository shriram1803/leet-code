class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int curr_start = 1;
        int d = 1, N;
        
        while(n > 0) {
            N = min(7, n);
            res += (N*(2*curr_start + (N - 1)*d))/2;
            curr_start += 1;
            n -= 7;            
        }
        
        return res;
    }
};