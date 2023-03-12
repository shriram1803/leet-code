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
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        for(auto head : lists) {
            while(head) {
                pq.push(head);
                head = head->next;
            }
        }
        ListNode* ret = new ListNode();
        ListNode* curr = ret;
        while(!pq.empty()) {
            curr->next = pq.top();
            curr = curr->next, curr->next = nullptr;
            pq.pop();
        }
        return ret->next;
    }
};