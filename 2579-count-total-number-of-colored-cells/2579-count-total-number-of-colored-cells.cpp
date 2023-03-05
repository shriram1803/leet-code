class Solution {
public:
    long long coloredCells(int n) {
        
        long long res = 0;
        
        int curr = 2 * n - 1;
        
        res += curr;
        
        while(1) {
            
            curr -= 2;
            
            if(curr <= 0) 
                break;
            
            res += 2 * curr;
            
        }
        
        return res;
        
    }
};