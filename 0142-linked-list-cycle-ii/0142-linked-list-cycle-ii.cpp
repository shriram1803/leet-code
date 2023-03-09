/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
        while(fast and fast->next) {
            fast = fast->next->next, slow = slow->next;
            if(slow == fast) 
                break;
        }
        if(!fast or !fast->next) {
            return nullptr;
        }
        slow = head;
        while(slow != fast) {
            fast = fast->next, slow = slow->next;
        }
        return slow;
    }
};