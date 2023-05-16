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
    void swap_node(ListNode* pre, ListNode* first, ListNode* second) {
        pre->next = second;
        first->next = second->next;
        second->next = first;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode* slow = new ListNode();
        ListNode* save = slow;
        ListNode* fast = head->next;
        slow->next = head;
        while(fast) {
            swap_node(slow, slow->next, fast);
            slow = fast->next;
            fast = slow->next ? slow->next->next : nullptr;
        }
        return save->next;
    }
};