class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> res(queries.size()), nums(n + 2, 0);
        int curr = 0;
        for(int i = 0; i < queries.size(); ++i) {
            int ind = queries[i][0] + 1, col = queries[i][1];
            if(nums[ind] != 0)
                curr -= ((nums[ind - 1] == nums[ind]) + (nums[ind] == nums[ind + 1]));
            nums[ind] = col;
            curr += ((nums[ind - 1] == nums[ind]) + (nums[ind] == nums[ind + 1]));     
            res[i] = curr;
        }
        return res;
    }
};