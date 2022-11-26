class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        const int n = arr.size();
        
        for(int i = 0, x = 0; i < n; ++i) {
            x = arr[i];
            for(int j = i + 1; j < n; ++j) {
                for(int k = j, y = 0; k < n; ++k) {
                    y ^= arr[k];
                    if(x == y) cnt++;
                }
                x ^= arr[j];
            }
        }
        
        return cnt;
    }
};