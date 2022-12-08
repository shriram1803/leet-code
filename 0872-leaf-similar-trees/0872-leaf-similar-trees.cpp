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
    void createVector(TreeNode* root, vector<int> &v)
    {
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            v.push_back(root->val);
            return;
        }
        createVector(root->left, v);
        createVector(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        createVector(root1, a);
        createVector(root2, b);
        return a == b;
    }
};