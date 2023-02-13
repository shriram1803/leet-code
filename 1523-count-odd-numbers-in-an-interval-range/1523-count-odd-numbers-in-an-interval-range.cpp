class Solution {
public:
    int countOdds(int low, int high) {
        if(high == low) return high % 2 != 0;
        if(high % 2 == 0) 
            high -= 1;
        return 1 + (high - low) / 2;
    }
};