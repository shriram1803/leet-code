/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<ListNode*, int>> s;
        vector<int> res;
        while(head) {
            while(!s.empty() and s.top().first->val < head->val) {
                res[s.top().second] = head->val, s.pop();
            }
            s.push({head, res.size()});
            res.emplace_back(0);
            head = head->next;
        }
        return res;
    }
};