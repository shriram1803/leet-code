class Solution {
public:
    bool canFind(int pigs, int buckets, int attempts) {
        return pow(attempts + 1, pigs) >= buckets;
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attempts = minutesToTest / minutesToDie;
        int left = 0, right = buckets, mid;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(canFind(mid, buckets, attempts)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};