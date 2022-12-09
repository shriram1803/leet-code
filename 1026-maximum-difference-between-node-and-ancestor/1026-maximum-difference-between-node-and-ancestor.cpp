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
    int maxAncestorDiff(TreeNode* root, int min_path = INT_MAX, int max_path = INT_MIN) {
        if(!root) return max_path - min_path;
        max_path = max(max_path, root->val), min_path = min(min_path, root->val);
        return max(maxAncestorDiff(root->left, min_path, max_path), maxAncestorDiff(root->right, min_path, max_path));
    }
};