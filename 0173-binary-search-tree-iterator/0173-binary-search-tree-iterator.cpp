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
    TreeNode* node = new TreeNode();
    void build(TreeNode* root) {
        if(!root) return;
        build(root->left);
        node->right = root;
        node = node->right;
        build(root->right);
    }
    BSTIterator(TreeNode* root) {
        TreeNode* store = node;
        build(root);
        node = store, node = node->right;
    }
    
    int next() {
        int save = node->val;
        node = node->right;
        return save;
    }
    
    bool hasNext() {
        return node ? 1 : 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */