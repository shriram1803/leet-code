class Solution {
public:
    int f(int N, int k) {
        if(N == 1)
            return 0;
        
        int res; 
        
        if(k <= N / 2) {
            res = f(N / 2, k);
        } else {
            res = !f(N / 2, k - N / 2);
        }
        
        return res;
    }
    int kthGrammar(int n, int k) {
        return f(pow(2, n), k);
    }
};