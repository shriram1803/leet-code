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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
            return {};
        
        int cur_max;
        int sz;
        TreeNode* curr;
        vector<int> res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()) {
            cur_max = INT_MIN;
            sz = q.size();
            
            while(sz--) {
                curr = q.front();
                q.pop();
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
                
                cur_max = max(cur_max, curr->val);
            }
            
            res.emplace_back(cur_max);
        }
        
        return res;
    }
};