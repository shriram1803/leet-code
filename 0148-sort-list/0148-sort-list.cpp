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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* curr = new ListNode();
        ListNode* save = curr;
        while(a and b) {
            if(a->val < b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        if(a) {
            curr->next = a;
        }
        if(b) {
            curr->next = b;
        }
        return save->next;
    }
    ListNode* mergeSort(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* slow = head,* fast = head->next;
        while(fast and fast->next) {
            slow = slow->next, fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return merge(mergeSort(head), mergeSort(fast));
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};