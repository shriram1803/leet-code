class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> res;
        for(auto num : nums) m[num]++;
        for(auto num : nums) {
            if(m[num] == 1 and m.find(num - 1) == m.end() and m.find(num + 1) == m.end()) {
                res.emplace_back(num);
            }
        }
        return res;
    }
};