class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(int val : arr) m[(val % k + k) % k]++;
        if(m[0] % 2 == 1) return false;
        for(int i = 1; i < k; ++i) {
            if(m[i] != m[k - i])
                return false;
        }
        return true;
    }
};