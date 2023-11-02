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
    pair<int, int> dfs(TreeNode* root, int& res) {
        if(!root)
            return {0, 0};
        
        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        
        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;
        
        res += (root->val == sum / count);
        
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};