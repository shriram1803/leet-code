class Solution {
public:
    int point(vector<int>& nums, int ind, int col) {
        int match = 0;
        if(ind > 0 and nums[ind - 1] == col)
            match += 1;
        if(ind < nums.size() - 1 and nums[ind + 1] == col)
            match += 1;
        return match;
    }
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> res(queries.size()), nums(n, 0);
        int curr = 0;
        for(int i = 0; i < queries.size(); ++i) {
            int ind = queries[i][0], col = queries[i][1];
            if(nums[ind] != 0)
                curr -= point(nums, ind, nums[ind]);
            nums[ind] = col;
            curr += point(nums, ind, col);
            
            res[i] = curr;
        }
        return res;
    }
};