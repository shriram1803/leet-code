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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [&](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for(auto head : lists) {
            if(head) {
                pq.push(head);
            }
        }
        ListNode* ret = new ListNode();
        ListNode* curr = ret;
        while(!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if(curr->next) {
                pq.push(curr->next);
                curr->next = nullptr;
            }
        }
        return ret->next;
    }
};