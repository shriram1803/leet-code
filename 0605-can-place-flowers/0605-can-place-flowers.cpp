class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int N = fb.size();
        for(int i = 0; i < N; ++i) {
            if(fb[i] == 0) {
                if((i == 0 or fb[i - 1] == 0) and (i == N - 1 or fb[i + 1] == 0)) {
                    n -= 1;
                    fb[i] = 1;
                }
            }
            if(n <= 0)
                return true;
        }
        return n <= 0;
    }
};