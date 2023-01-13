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
    int res = 1;
    int dfs(TreeNode* root, int prev) {
        if(!root) return 0;
        int lft = dfs(root->left, root->val);
        int rht = dfs(root->right, root->val);
        int local_max = max(0, max(lft, rht));
        res = max(res, 1 + lft + rht);
        if(root->val != prev) return 0;
        return 1 + local_max;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root, 1001);
        return res - 1;
    }
};