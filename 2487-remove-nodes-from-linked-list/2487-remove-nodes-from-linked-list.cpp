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
    ListNode* reverse(ListNode* curr, ListNode* pre){
        if(!curr)
            return pre;
        ListNode *temp = curr->next;
        curr->next = pre;
        return reverse(temp, curr);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head or !head->next) return head;
        
        ListNode* rev = reverseList(head);
        head = rev;
        
        while(head) {
            int val = head->val;
            ListNode* t = head->next;
            while(t and t->val < val) t = t->next;
            head->next = t;
            head = head->next;
        }
        
        return reverseList(rev);
    }
};