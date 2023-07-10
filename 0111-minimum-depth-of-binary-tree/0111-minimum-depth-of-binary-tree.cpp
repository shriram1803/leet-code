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
    int f(TreeNode* root) {
        if(!root)
            return 1e9;
        if(!root->left and !root->right)
            return 1;
        return 1 + min(f(root->left), f(root->right));
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        return f(root);
    }
};