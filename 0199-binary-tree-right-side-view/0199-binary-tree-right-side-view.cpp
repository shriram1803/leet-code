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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        
        deque<TreeNode*> q = {root};
        vector<int> res;
        
        while(!q.empty()) {
            int sz = q.size();
            res.emplace_back(q.back()->val);
            while(sz--) {
                if(q.front()->left)
                    q.push_back(q.front()->left);
                if(q.front()->right)
                    q.push_back(q.front()->right);
                q.pop_front();
            }
        }
        
        return res;
    }
};