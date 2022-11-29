/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res = nullptr;
    // int global = INT_MAX;
    int solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return 0;
        int local = 0;
        if(root->val == p->val or root->val == q->val) local++;
        local += solve(root->left, p, q) + solve(root->right, p, q);
        if(local == 2 and res == nullptr) {
            // if(root->val > global) {
            //     res = root;
            //     global = root->val;
            // }
            res = root;
        }
        return local;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return res;
    }
};