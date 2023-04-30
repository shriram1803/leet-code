class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), common_cnt = 0;
        vector<int> freq(n + 1, 0), res(n, 0);
        for(int i = 0; i < n; ++i) {
            freq[A[i]] += 1;
            if(freq[A[i]] == 2)
                common_cnt += 1;
            freq[B[i]] += 1;
            if(freq[B[i]] == 2)
                common_cnt += 1;
            res[i] = common_cnt;
        }
        return res;
    }
};