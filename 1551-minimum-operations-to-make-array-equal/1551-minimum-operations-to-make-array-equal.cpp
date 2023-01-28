class Solution {
public:
    int minOperations(int n) {
        int a = n % 2 == 0 ? 1 : 2, d = 2, N = n / 2;
        return (2 * a + (N - 1) * d) * N / 2;
    }
};