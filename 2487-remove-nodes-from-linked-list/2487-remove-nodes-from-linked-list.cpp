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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> v;
        ListNode* curr = head;
        while(curr) {
            while(v.size() and v.back()->val < curr->val) v.pop_back();
            v.emplace_back(curr);
            curr = curr->next;
        }
        for(int i = 1; i < v.size(); ++i) {
            v[i - 1]->next = v[i];
        }
        v.back()->next = nullptr;
        return v[0];
    }
};