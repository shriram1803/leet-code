class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return false;
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int prev = 0, minn = INT_MAX, prime_cnt = 0;
        vector<int> res(2, -1);
        if(left <= 2) {
            prev = 2;
            prime_cnt = 1;
        }
        if(left % 2 == 0) ++left;
        for(int i = left; i <= right; i += 2) {
            if(isPrime(i)) {
                if(prime_cnt < 1) {
                    ++prime_cnt;
                } else {
                    if(i - prev < minn) {
                        minn = i - prev;
                        res[0] = prev, res[1] = i;
                    }
                }
                prev = i;
            }
        }
        return res;
    }
};