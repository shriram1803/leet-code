class Solution {
public:
    int addMinimum(string word) {
        int res = 0;
        int vi = 0;
        int ind = 0, n = word.size();
        while(ind < n) {
            if(word[ind] != 'a' + (vi % 3)) {
                res += 1;
            } else {
                ind += 1;
            }
            vi += 1;
        }        
        res += 2 - ((vi - 1) % 3);
        return res;
    }
};