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
class Solution {
public:
    int res = INT_MIN;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int lft = root->val + dfs(root->left);
        int rht = root->val + dfs(root->right);
        int val = max(lft, rht);
        val = root->val < val ? val : root->val;
        res = max(res, val);
        res = max(res, lft + rht - root->val); 
        return val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};