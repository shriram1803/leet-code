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
    int i = 0;
    void build(string s, vector<vector<int>>& v) {
        int dash_cnt = 0, ind = 0, n = s.size();
        while(ind < n) {
            if(s[ind] != '-') {
                string temp = "";
                while(ind < n and s[ind] != '-') temp += s[ind], ++ind;
                v.push_back({stoi(temp), dash_cnt});
                dash_cnt = 0;
            } else {
                ++dash_cnt;
                ++ind;
            }
        }
    }
    TreeNode* recover(vector<vector<int>>& nodes, int depth) {
        if(i >= nodes.size() or nodes[i][1] < depth) return nullptr;
        TreeNode* node = new TreeNode(nodes[i++][0]);
        node->left = recover(nodes, depth + 1);
        node->right = recover(nodes, depth + 1);
        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        vector<vector<int>> nodes;
        build(traversal, nodes);
        return recover(nodes, 0);
    }
};