class Solution {
public:
    bool check(vector<int>& piles, int& k, int& h) {
        int c = 0;
        for(int p : piles) {
            c += (p + k - 1) / k;
        }
        return c <= h; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(check(piles, mid,  h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};