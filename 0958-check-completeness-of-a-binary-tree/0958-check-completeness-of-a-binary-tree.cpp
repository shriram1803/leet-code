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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int expected_nodes = 1;
        while(!q.empty()) {
            int t = q.size();
            int save = t;
            bool foundNull = false;
            while(t--) {
                auto curr = q.front(); q.pop();
                if(curr->left) {
                    if(foundNull)
                        return false;
                    q.push(curr->left);
                } else {
                    foundNull = true;
                }
                if(curr->right) {
                    if(foundNull) {
                        return false;
                    }
                    q.push(curr->right);
                } else {
                    foundNull = true;
                }
            }            
            if(!q.empty() and expected_nodes != save)
                return false;
            expected_nodes *= 2;
        }
        return true;
    }
};