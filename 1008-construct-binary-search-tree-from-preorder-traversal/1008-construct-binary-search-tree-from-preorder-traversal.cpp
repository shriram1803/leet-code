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
    int ind = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int val = 1001) {
        if(ind >= preorder.size() or preorder[ind] > val) return nullptr;
        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, val);
        return root;
    }
};