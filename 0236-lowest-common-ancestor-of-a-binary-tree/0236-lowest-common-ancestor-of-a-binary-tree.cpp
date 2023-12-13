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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        
        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);

        bool curr = root == p || root == q;
        
        if(curr or (curr and left) or (curr and right) or (left and right))
            return root;
        
        if(left)
            return left;
        
        if(right)
            return right;
        
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};