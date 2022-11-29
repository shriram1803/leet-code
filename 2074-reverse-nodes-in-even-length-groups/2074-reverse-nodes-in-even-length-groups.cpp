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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* curr = head, * prev = head;
        int n = 0, grp = 1, visited = 0;
        while(curr) curr = curr->next, n++;
        curr = head;
        while(curr and curr->next) {
            int t = grp;
            if((grp % 2 and (visited + grp) <= n) or (visited + grp > n and (n - visited)%2 == 1)) {
                while(--t >= 0 and curr) prev = curr, curr = curr->next;
            } else {
                ListNode* save = prev, * nxt = nullptr;
                while(--t >= 0 and curr) 
                {
                    nxt = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                }
                save->next->next = curr;
                nxt = save->next;
                save->next = prev;
                prev = nxt;
            }
            visited += grp;
            grp += 1;
        }
       
        return head;
    }
};