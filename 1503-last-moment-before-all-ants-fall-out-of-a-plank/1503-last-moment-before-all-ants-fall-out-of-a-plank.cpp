class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int last_one = 0;
        for(int l : left) {
            last_one = max(last_one, l);
        } 
        for(int r : right) {
            last_one = max(last_one, n - r);
        }
        return last_one;
    }
};