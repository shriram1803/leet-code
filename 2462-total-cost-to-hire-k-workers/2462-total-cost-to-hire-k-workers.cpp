class Solution {
public:
    long long totalCost(vector<int>& c, int k, int ca) {
        long long res = 0;
        priority_queue<int, vector<int>, greater<int> > a, b;
        int s = 0, e = c.size() - 1;
        int rem = c.size();
        for(int i = 0; i < ca; ++i){
            a.push(c[s]);
            s++;
        }
        for(int i = 0; i < ca and s <= e; ++i){
            b.push(c[e]);
            e--;
        }
        while(k-- > 0){            
            if(!a.size()){
                res += b.top();
                b.pop();
                if(s <= e) a.push(c[s]), s++;
            } else if(!b.size()) {
                res += a.top();
                a.pop();
            } else {
                if(a.top() == b.top() or a.top() < b.top()){
                    res += a.top();
                    a.pop();
                    if(s <= e) a.push(c[s]), s++;
                }else{
                    res += b.top();
                    b.pop();
                    if(s <= e) b.push(c[e]), e--;
                }
            }
        }
        return res;
    }
};