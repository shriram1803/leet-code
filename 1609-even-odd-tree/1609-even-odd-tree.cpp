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
    bool isEvenOddTree(TreeNode* root) {
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            if(lvl++ % 2 == 0) {
                int prev = INT_MIN;
                int t = q.size();
                while(t--) {
                    TreeNode* curr = q.front(); 
                    if(prev >= curr->val or curr->val % 2 == 0) return false;
                    prev = curr->val;
                    q.pop();
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            } else {
                int prev = INT_MAX;
                int t = q.size();
                while(t--) {
                    TreeNode* curr = q.front(); 
                    if(prev <= curr->val or curr->val % 2 == 1) return false;
                    prev = curr->val;
                    q.pop();
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
        }
        return true;
    }
};