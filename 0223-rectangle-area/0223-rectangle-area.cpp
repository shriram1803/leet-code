class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int area = 0;
        set<pair<int, int>> s;
        int x = bx1, y = by1;
        for(int i = y; i < by2; ++i) {
            for(int j = x; j < bx2; ++j) {
                s.insert({i, j});
            }
        }
        x = ax1, y = ay1;
        for(int i = y; i < ay2; ++i) {
            for(int j = x; j < ax2; ++j) {
                s.insert({i, j});
            }
        }
        return s.size();
    }
};