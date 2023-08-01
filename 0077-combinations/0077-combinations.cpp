class Solution {
public:
    void backtrack(int curr_num, const int n, int k, vector<int>& curr, vector<vector<int>>& res) {
        
        if(k == 0) {
            res.emplace_back(curr);
            return;
        }
        
        if(curr_num > n)
            return;
        
        
        curr.emplace_back(curr_num);
        backtrack(curr_num + 1, n, k - 1, curr, res);
        curr.pop_back();
        
        backtrack(curr_num + 1, n, k, curr, res);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        
        backtrack(1, n, k, curr, res);
        
        return res;
    }
};