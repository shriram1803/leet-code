/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void construct_parent_hash(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, TreeNode*>& mp) {
        if(!root)
            return;
        mp[root] = prev;
        construct_parent_hash(root->left, root, mp);
        construct_parent_hash(root->right, root, mp);
    }
    
    void bfs(TreeNode* root, int k, unordered_map<TreeNode*, TreeNode*>& ph, vector<int>& res) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis{root};
        q.push(root);
        
        while(!q.empty() and k--) {
            int t = q.size();
            while(t--) {
                auto curr = q.front();
                q.pop();
                if(curr->left and !vis.count(curr->left)) q.push(curr->left), vis.insert(curr->left);
                if(curr->right and !vis.count(curr->right)) q.push(curr->right), vis.insert(curr->right);
                if(ph[curr] and !vis.count(ph[curr])) q.push(ph[curr]), vis.insert(ph[curr]);
            }
        }
        
        while(!q.empty()) {
            res.emplace_back(q.front()->val);
            q.pop();
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_hash;
        construct_parent_hash(root, nullptr, parent_hash);
        
        vector<int> res;
        
        bfs(target, k, parent_hash, res);
        
        return res;
    }
};