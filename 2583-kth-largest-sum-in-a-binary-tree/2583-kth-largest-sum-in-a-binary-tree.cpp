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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            
            int t = q.size();
            
            long long curr_sum = 0;
            
            while(t--)  {
                
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                
                curr_sum += q.front()->val;
                
                q.pop();
                
            }
            
            pq.push(curr_sum);
            
            if(pq.size() > k)
                pq.pop();
            
        }
        
        return pq.size() >= k ? pq.top() : -1;
        
    }
};