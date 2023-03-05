class Solution {
public:
    long long coloredCells(int n) {
        
        long long res = (n * ((long long)2 + (n - (long long)1) * (long long)2)) / (long long)2;
        
        res = (res * 2) - (2 * n - 1);
        
        return res;
        
    }
};