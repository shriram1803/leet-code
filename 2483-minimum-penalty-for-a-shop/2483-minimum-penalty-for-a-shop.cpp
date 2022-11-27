class Solution {
public:
    int bestClosingTime(string customers) {
        
        const int n = customers.size();
        
        int res = n, least_pen = 0, pen = 0;
        
        for(auto ch : customers) {
            if(ch == 'N') pen++;
        }
        least_pen = pen;
        
        for(int i = n - 1; i >= 0; --i) {
            if(customers[i] == 'Y') pen++;
            else pen--;
            if(pen <= least_pen) {
                res = i;
                least_pen = pen;
            }
        }
        
        return res;
    }
};