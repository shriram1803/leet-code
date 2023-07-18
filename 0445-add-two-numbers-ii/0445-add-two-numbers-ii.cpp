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
    ListNode* reverse_list(ListNode* curr) {
        ListNode* prev = nullptr, * next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rev1 = reverse_list(l1);
        ListNode* rev2 = reverse_list(l2);
        ListNode* ret = new ListNode();
        ret->next = rev1;
        
        int balance = 0;
        while(rev1 and rev2) {
            balance += rev1->val + rev2->val;            
            rev1->val = balance % 10;
            balance = balance / 10;
            rev1 = rev1->next, rev2 = rev2->next;
        }
        
        while(rev1) {
            balance += rev1->val;         
            rev1->val = balance % 10;
            balance = balance / 10;
            rev1 = rev1->next;
        }
        
        if(rev2)
            l1->next = rev2;
        while(rev2) {
            balance += rev2->val;        
            rev2->val = balance % 10;
            balance = balance / 10;
            rev2 = rev2->next;
        }
        
        
        if(balance > 0) {
            ListNode* head = new ListNode(balance);
            head->next = reverse_list(ret->next);
            return head;
        }
        return reverse_list(ret->next);
    }
};