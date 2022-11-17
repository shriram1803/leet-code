class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> current, int curr_val, int target, const int k) 
    {
        if(target < 0 or current.size() > k) return;
        if(target == 0 and current.size() == k) {
            res.push_back(current);
            return;
        }
        for(int i = curr_val; i <= 9; ++i) {
            current.push_back(i);
            solve(current, i + 1, target - i, k);
            current.pop_back();
        } 
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        solve(v, 1, n, k);
        return res;
    }
};