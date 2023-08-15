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
    ListNode* partition(ListNode* head, int x) {
        ListNode* a = new ListNode();
        ListNode* b = new ListNode();
        ListNode* ret = a;
        ListNode* save = b;
        
        while(head) {
            if(head->val < x) {
                a->next = head;
                if(a->next)
                    a = a->next;
                head = head->next;
                a->next = nullptr;
            } else {
                b->next = head;
                b = b->next;
                head = head->next;
                b->next = nullptr;
            }
        }
        
        a->next = save->next;
        
        return ret->next;
    }
};