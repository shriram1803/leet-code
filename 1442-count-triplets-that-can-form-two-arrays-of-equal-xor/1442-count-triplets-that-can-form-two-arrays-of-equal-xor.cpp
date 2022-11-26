class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        const int n = arr.size();
        unordered_map<int, vector<int>> m;
        
        m[0].push_back(-1);
        for(int i = 0, x = 0; i < n; ++i) {
            x ^= arr[i];
            if(m.find(x) != m.end()) {
                for(auto val : m[x]) {
                    cnt += (i - val) - 1;
                }
            }
            m[x].emplace_back(i);
        }
        
        return cnt;
    }
};