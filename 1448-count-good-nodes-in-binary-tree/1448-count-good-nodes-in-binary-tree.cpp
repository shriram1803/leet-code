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
    void dfs(TreeNode* root, int cur_max, int &good_cnt) {
        if(!root)
            return;
        
        if(root->val >= cur_max) {
            cur_max = root->val;
            good_cnt += 1;
        }
        
        dfs(root->left, cur_max, good_cnt);
        dfs(root->right, cur_max, good_cnt);
    }
    int goodNodes(TreeNode* root) {
        int good_cnt = 0;
        dfs(root, -1e9, good_cnt);
        return good_cnt;
    }
};