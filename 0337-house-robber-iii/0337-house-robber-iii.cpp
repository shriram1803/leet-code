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
    int f(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if(!root)
            return 0;
        
        if(m.count(root))
            return m[root];
        
        int left_not_pick, right_not_pick, left_pick = 0, right_pick = 0;
        
        //Left child Not Pick case
        left_not_pick = f(root->left, m);
        //Left child Pick case
        if(root->left) {
            left_pick = f(root->left->left, m) + f(root->left->right, m);
        }
        
        //Right child Not Pick case
        right_not_pick = f(root->right, m);
        //Right child Pick case
        if(root->right) {
            right_pick = f(root->right->left, m) + f(root->right->right, m);
        }
        
        
        m[root] = max(left_not_pick + right_not_pick, root->val + left_pick + right_pick);
        
        
        return m[root];
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        TreeNode* ret = new TreeNode();
        ret->left = root;
        return f(ret, m);
    }
};