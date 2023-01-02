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
    void insert(TreeNode* curr, int val) {
        if(val < curr->val) {
            if(curr->left) {
                insert(curr->left, val);
            } else {
                curr->left = new TreeNode(val);
            }
        } else {
            if(curr->right) {
                insert(curr->right, val);
            } else {
                curr->right = new TreeNode(val);
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); ++i) {
            insert(root, preorder[i]);
        }
        return root;
    }
};