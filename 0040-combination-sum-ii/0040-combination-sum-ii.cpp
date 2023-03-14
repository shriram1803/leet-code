class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int>& v, int ind, int target, vector<int>& curr) {
        if(target == 0) {
            res.emplace_back(curr);
            return;
        }
        
        if(target < 0 or ind >= v.size()) return;
        
        curr.emplace_back(v[ind]);
        solve(v, ind + 1, target - v[ind], curr);
        curr.pop_back();
        
        ind += 1;
        
        while(ind < v.size() and v[ind - 1] == v[ind]) ind += 1;
        
        solve(v, ind, target, curr);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, current);
        return res;
    }
};