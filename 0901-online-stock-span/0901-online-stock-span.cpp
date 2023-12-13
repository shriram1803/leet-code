class StockSpanner {
public:
    stack<pair<int, int>> s;
    int current_day = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        current_day += 1;
        while(!s.empty() and s.top().first <= price)
            s.pop();
        if(!s.empty())
            res = current_day - s.top().second;
        else
            res = current_day;
        s.push({price, current_day});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */