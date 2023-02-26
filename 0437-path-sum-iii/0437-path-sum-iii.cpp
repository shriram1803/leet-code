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
    int res = 0;
    void dfs(TreeNode* root, unordered_map<long long, int>& diffs, long long curr, int target) {
        
        if(!root) return;
        
        curr += root->val;
        
        long long curr_diff = curr - target;
        
        int exists = diffs[curr_diff];

        diffs[curr] += 1;

        res += exists;

        dfs(root->left, diffs, curr, target);
        dfs(root->right, diffs, curr, target);
        
        diffs[curr] -= 1;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> diffs;
        diffs[0] = 1;
        dfs(root, diffs, 0, targetSum);
        return res;
    }
};