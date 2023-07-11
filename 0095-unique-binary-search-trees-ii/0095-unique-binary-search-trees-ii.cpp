/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
vector<vector<vector<TreeNode*>>> dp(9, vector<vector<TreeNode*>>(9));
class Solution {
public:
    vector<TreeNode*> f(int start, int end) {
        if(start > end)
            return {nullptr};
        
        if(dp[start][end].size())
            return dp[start][end];
        
        vector<TreeNode*> res;
        for(int i = start; i <= end; ++i) {
            auto left = f(start, i - 1);
            auto right = f(i + 1, end);
            for(auto& l : left) {
                for(auto& r : right) {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l, curr->right = r;
                    res.emplace_back(curr);
                }
            }
        }
        return dp[start][end] = res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return f(1, n);
    }
};