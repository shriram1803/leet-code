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
    string dfs(TreeNode* root) {
        if(!root)
            return "";
        
        string left = dfs(root->left);
        string right = dfs(root->right);
        string curr = to_string(root->val);
        
        if(!right.empty()) { 
            curr += "(";           
            if(!left.empty())
                curr += left;
            curr += ")";
            curr += "(" + right + ")";
        } else {            
            if(!left.empty())
                curr += "(" + left + ")";
        }
            
        
        return curr;
    }
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};