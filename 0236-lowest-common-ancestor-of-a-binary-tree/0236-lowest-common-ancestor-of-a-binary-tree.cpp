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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        // int local = 0;
        TreeNode* l = solve(root->left, p, q);
        TreeNode* r = solve(root->right, p, q);
        
        if((l or root == p or root == q) and (r or root == p or root == q)) return root;
        if(l) return l;
        if(r) return r;
        
        if(root == p or root == q) return root;
        
        return nullptr;
        
//         if((l == p or l == q) and (r == p or r == q)) {
//             return root;
//         }
        
//         if((root == p or root == q) and (r == p or r == q)) {
//             return root;
//         }
        
//         if((l == p or l == q) and (root == p or root == q)) {
//             return root;
//         }
        
//         return nullptr;
        
        
//         if(l == p or l == q) return l;
        
//         if(r == p or r == q) return r;
        
        // if(root == p or root == q) local++;
        // local += solve(root->left, p, q) + solve(root->right, p, q);
        // if(local == 2 and res == nullptr) {
        //     res = root;
        // }
        
        
        // return local;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
        return res;
    }
};