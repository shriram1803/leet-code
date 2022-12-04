class Solution {
public:
    int pivotInteger(int n) {
        int total = 0;
        for(int i = 1; i <= n; ++i) total += i;
        int curr = 0;
        for(int i = 1; i <= n; ++i) {
            curr += i;
            if(total == curr) return i;
            total -= i;
        }
        return -1;
    }
};