class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long n = 0;
        vector<int> res(word.size(), 0);
        for(int i = 0; i < word.size(); ++i) {
            int curr = word[i] - '0';
            n = n * 10 + curr;
            n %= m;
            if(n == 0) {
                res[i] = 1;
            }
        }
        return res;
    }
};