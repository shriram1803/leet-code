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
    TreeNode* dfs(int val, unordered_map<int, int>& left, unordered_map<int, int>& right) 
    {
        TreeNode* node = new TreeNode(val);
        if(left.find(val) != left.end()) node->left = dfs(left[val], left, right);
        if(right.find(val) != right.end()) node->right = dfs(right[val], left, right); 
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> left, right;
        unordered_set<int> children, parents;
        for(auto& d : descriptions) {
            parents.insert(d[0]);
            children.insert(d[1]);
            if(d[2] == 1) {
                left[d[0]] = d[1];
            } else {
                right[d[0]] = d[1];
            }
        }
        for(auto it : parents) {
            if(!children.count(it))
                return dfs(it, left, right);
        }
        return nullptr;
    }
};