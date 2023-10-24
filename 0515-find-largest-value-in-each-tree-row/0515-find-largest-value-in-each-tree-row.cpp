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
    map<int, int> m;
    void dfs(TreeNode* root, int level) {
        if(!root)
            return;
        if(m.count(level))
            m[level] = max(m[level], root->val);
        else
            m[level] = root->val;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root, -1);
        vector<int> res;
        for(auto& it : m) {
            res.emplace_back(it.second);
        }
        return res;
    }
};