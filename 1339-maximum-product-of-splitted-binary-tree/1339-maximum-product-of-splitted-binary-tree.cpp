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
    const int MOD = 1e9 + 7;
    int solve(TreeNode* root, long tot, long &res) {
        if(!root) return 0;
        int sub = root->val + solve(root->left, tot, res) + solve(root->right, tot, res);
        res = max(res, ((tot - sub) * sub));
        return sub;
    }
    int maxProduct(TreeNode* root) {
        long res = 0;
        long tot = solve(root, 0, res);
        solve(root, tot, res);
        return res % MOD;
    }
};