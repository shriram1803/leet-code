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
vector<vector<TreeNode*>> dp(21);
class Solution {
public:
    vector<TreeNode*> f(int n) {
        if(n == 1)
            return {new TreeNode()};
        
        if(dp[n].size() > 0) 
            return dp[n];
        
        vector<TreeNode*> res;
        
        for(int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = f(i);
            vector<TreeNode*> right = f(n - i - 1);
            for(auto& l : left) {
                for(auto& r : right) {
                    TreeNode* curr = new TreeNode();
                    curr->left = l, curr->right = r;
                    res.push_back(curr);
                }
            }
        }
        
        return dp[n] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return f(n);
    }
};