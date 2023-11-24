class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res = 0;
        int picks = piles.size() / 3;
        sort(piles.begin(), piles.end());
        for(int i = piles.size() - 2; picks > 0; i -= 2, picks -= 1)
            res += piles[i];
        return res;
    }
};