class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        int i = 0;
        int n = target;
        while(n > 1) {
            if(maxDoubles == 0) {
                moves += (n - 1);
                break;
            } else {
                moves++;
                if(n % 2) {
                    --n;
                } else {
                    n /= 2;
                    --maxDoubles;
                }
            }
        }
        return moves;
    }
};