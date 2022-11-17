class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        int xOverlap = max(min(ax2,bx2)-max(ax1,bx1), 0);
        int yOverlap = max(min(ay2,by2)-max(ay1,by1), 0);
        int ar = xOverlap * yOverlap;
        return area - ar;
    }
};