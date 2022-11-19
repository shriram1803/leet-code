class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int>& v, int ind, int target, vector<int>& curr) {
        if(target < 0) return;
        if(target == 0) {
            res.emplace_back(curr);
            return;
        }
        for(int i = ind; i < v.size(); ++i) {
            if(i != ind and i > 0 and v[i] == v[i - 1]) continue;
            curr.emplace_back(v[i]);
            solve(v, i + 1, target - v[i], curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, current);
        return res;
    }
};