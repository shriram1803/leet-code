class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        vector<int> open(n + 1), close(n + 1);
        
        int prev = customers[0] == 'N';
        for(int i = 1; i <= n; ++i) {
            open[i] = prev;
            prev += customers[i] == 'N';
        }
        
        for(int i = n - 1; i >= 0; --i) {
            close[i] += close[i + 1] + (customers[i] == 'Y');
        }
        
        int min_res = n;
        int mini = 1e9;
        for(int i = n; i >= 0; --i) {
            if(open[i] + close[i] <= mini) {
                mini = open[i] + close[i];
                min_res = i;
            }
        }
        
        return min_res;
    }
};