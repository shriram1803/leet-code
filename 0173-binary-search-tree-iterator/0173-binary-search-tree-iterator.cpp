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
    TreeNode* node;
    BSTIterator(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> s;
        TreeNode* curr = root, *prev = new TreeNode();
        node = prev;
        while(curr or s.size()) {
            if(curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                prev->right = s.top();
                prev = prev->right;
                curr = s.top()->right;
                s.pop();
            }
        }
        node = node->right;
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