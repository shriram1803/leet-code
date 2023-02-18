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
    int prev = -1e6, minn = 1e6;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        minn = min(minn, root->val - prev);
        prev = root->val;
        inorder(root->right);
    }    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minn;
    }
};