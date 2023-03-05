class Solution {
public:
    long long coloredCells(int n) {
        
        long long start = 1, diff = 2;
        
        long long res = (n * (2 * start + (n - 1) * diff)) / 2;
        
        res = (res * 2) - (2 * n - 1);
        
        return res;
        
    }
};