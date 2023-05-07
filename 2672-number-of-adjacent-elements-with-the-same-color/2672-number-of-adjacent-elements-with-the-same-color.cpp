class Solution {
public:
    void handle(vector<int>& nums, int& curr, int ind, int col, int op) {
        if(ind > 0 and nums[ind - 1] == col)
            curr += op;
        if(ind < nums.size() - 1 and nums[ind + 1] == col)
            curr += op;
    }
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> res(queries.size()), nums(n, 0);
        int curr = 0;
        for(int i = 0; i < queries.size(); ++i) {
            int ind = queries[i][0], col = queries[i][1];
            if(nums[ind] != 0)
                handle(nums, curr, ind, nums[ind], -1);
            nums[ind] = col;
            handle(nums, curr, ind, col, 1);            
            res[i] = curr;
        }
        return res;
    }
};