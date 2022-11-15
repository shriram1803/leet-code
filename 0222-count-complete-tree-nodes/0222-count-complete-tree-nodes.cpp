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
    bool stop = false;
    int dfs(TreeNode* root, int depth, int curr) {
        if(stop) return 0;
        if(!root) {
            if(depth == curr) return 1;
            stop = true;
            return 0;
        }
        return dfs(root->right, depth, curr + 1) + 
            dfs(root->left, depth, curr + 1);
    }
    int countNodes(TreeNode* root) {
        TreeNode* curr = root;
        int depth = 0;
        while(curr) {
            curr = curr->left;
            depth++;
        }
        int cnt = pow(2, depth) - 1;
        cnt -= dfs(root, depth, 1);
        return cnt;
    }
};