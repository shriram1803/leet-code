class Solution {
public:    
    unordered_map<char, int> g_mapper = {
        {'M', 0}, {'P', 1}, {'G', 2}
    };
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int res = 0;
        vector<int> acc(3);
        vector<int> last(3);
        
        for(int i = 1; i < n - 1; ++i) {
            travel[i] += travel[i - 1];
        }
        
        for(int i = 0; i < n; ++i) {
            for(auto ch : garbage[i]) {
                ++acc[g_mapper[ch]];
                last[g_mapper[ch]] = i;
            }             
        }
        
        for(int i = 0; i < 3; ++i) {
            res += acc[i];
            if(last[i] > 0)
                res += travel[last[i] - 1];
        }
                
        return res;
    }
};