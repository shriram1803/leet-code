class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end(), greater<int>());
        int i;
        
        for(i = 0; i < c.size(); ++i) {
            if((i + 1) > c[i])
                break;
        }
        
        return i;
    }
};