class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            string s = to_string(i);
            bool isGood = false;
            for(char ch : s) {
                int v = ch - '0';
                if(v == 2 or v == 5 or v == 6 or v == 9) {
                    isGood = true;
                } else if(v == 3 or v == 4 or v == 7) {
                    isGood = false;
                    break;
                }
            }
            if(isGood) cnt++;
        }
        return cnt;
    }
};