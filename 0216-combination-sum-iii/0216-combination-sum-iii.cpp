class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> current, int curr_val, int curr_sz, int target, const int k) 
    {
        if(curr_sz == k) {
            if(target == 0) res.push_back(current);
            return;
        }
        for(int i = curr_val; i <= 9; ++i) {
            if(i > target) break;
            current.push_back(i);
            solve(current, i + 1, curr_sz + 1, target - i, k);
            current.pop_back();
        } 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(v, 1, 0, n, k);
        return res;
    }
};