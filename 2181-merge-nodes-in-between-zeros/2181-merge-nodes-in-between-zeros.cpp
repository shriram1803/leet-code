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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* slow = head, * fast = head->next;
        while(fast) {
            while(fast and fast->val != 0) {
                slow->val += fast->val;
                fast = fast->next;
            }
            slow->next = fast;
            if(fast->next)
                fast = fast->next;
            else {
                slow->next = nullptr;
                break;
            }
            slow = slow->next;
        }
        return head;
    }
};