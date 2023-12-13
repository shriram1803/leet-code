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
    pair<TreeNode*, int> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return {nullptr, 0}; 
        
        int local = 0;
        
        if(root == p) 
            local += 1;
        
        if(root == q)
            local += 1;
        
        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);
     
        local += left.second + right.second;
        
        if(local == 2)
            return {root, 0};
        
        if(left.first)
            return {left.first, 0};
        
        if(right.first)
            return {right.first, 0};        
        
        return {nullptr, local};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q).first;
    }
};