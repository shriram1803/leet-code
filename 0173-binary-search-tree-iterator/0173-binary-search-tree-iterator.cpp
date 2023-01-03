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
class BSTIterator {
public:
    int ind = 0, N;
    vector<int> inorder;
    void build(TreeNode* root) {
        if(!root) return;
        build(root->left);
        inorder.emplace_back(root->val);
        build(root->right);
    }
    BSTIterator(TreeNode* root) {
        build(root);
        N = inorder.size();
    }
    
    int next() {
        ++ind;
        return inorder[ind - 1];
    }
    
    bool hasNext() {
        return ind < N;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */