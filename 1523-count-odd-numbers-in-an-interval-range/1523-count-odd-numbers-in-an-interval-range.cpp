class Solution {
public:
    int countOdds(int low, int high) {
        int t = high - low;
        if(t % 2 == 0 and low % 2 == 0)
        {
            return t / 2;
        }
        return t / 2 + 1;
    }
};