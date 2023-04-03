class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int n = p.size();
        int boats = 0, picked = 0;
        sort(p.begin(), p.end());
        for(int i = 0, j = n - 1; i < j; ) {
            if(p[i] + p[j] <= limit) {
                boats += 1;
                i += 1, j -= 1;
            } else {
                j -= 1;
            }
        }
        return boats + (n - boats * 2);
    }
};