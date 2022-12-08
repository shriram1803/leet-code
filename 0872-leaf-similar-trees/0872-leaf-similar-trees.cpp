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
    void fillStack(TreeNode* root, stack<int> &s)
    {
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            s.push(root->val);
            return;
        }
        fillStack(root->left, s);
        fillStack(root->right, s);
    }
    bool checkStack(TreeNode* root, stack<int> &s)
    {
        if(!root){
            return true;
        }
        if(!root->left and !root->right){
            if(!s.empty() and s.top() == root->val) {
                s.pop();
                return true;
            }
            return false;
        }
        return checkStack(root->right, s) and checkStack(root->left, s);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<int> s;
        fillStack(root1, s);
        if(checkStack(root2, s) and !s.size()) return true;
        return false;
    }
};