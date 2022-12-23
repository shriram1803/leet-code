class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int smallest = INT_MAX;
        for(int price : prices) {
            if(price < smallest) {
                smallest = price;
            } else {
                res = max(res, price - smallest);
            }
        }
        return res;
    }
};