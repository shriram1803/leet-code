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
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        unordered_set<int> s;
        TreeNode* curr = root;
        vector<int> res;
        int prev = -1e9;
        int cont = 0;
        int max_sz = 0;
        while(curr or !st.empty()) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                st.pop();
                // cout << curr->val << endl;
                if(curr->val == prev)
                    cont += 1;
                else {
                    cont = 1;
                    prev = curr->val;
                }
                
                if(cont > max_sz) {
                    s.clear();
                    s.insert(curr->val);
                    max_sz = cont;
                } else if(cont == max_sz) {
                    s.insert(curr->val);
                }
                
                curr = curr->right;
            }
        }
        for(auto val : s)
            res.emplace_back(val);
        return res;
    }
};