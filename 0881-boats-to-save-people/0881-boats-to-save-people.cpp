class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(), p.end());
        int boats = 0;
        int front = 0, back = p.size() - 1;
        while(front < back) {
            if(p[front] + p[back] <= limit) {
                boats += 1;
                front += 1, back -= 1;
            } else {
                back -= 1;
            }
        }
        return p.size() - boats;
    }
};