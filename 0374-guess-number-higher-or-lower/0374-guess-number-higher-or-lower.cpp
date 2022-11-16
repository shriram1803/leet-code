/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    long long bs(long long start, long long end) {
        int mid = (start + end) / 2;
        if(guess(mid) == 0) return mid;
        if(guess(mid) == -1) return bs(start, mid - 1);
        return bs(mid + 1, end);
    }
    int guessNumber(int n) {
        return bs(0, n);
    }
};