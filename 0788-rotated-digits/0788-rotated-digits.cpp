class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            int temp = i;
            bool isGood = false;
            while(temp > 0) {
                int v = temp % 10;
                temp /= 10;
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