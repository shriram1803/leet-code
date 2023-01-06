class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0;
        sort(costs.begin(), costs.end());
        for(int cost : costs) {
            coins -= cost;
            if(coins < 0) {
                break;
            }
            ++res;
        }
        return res;
    }
};