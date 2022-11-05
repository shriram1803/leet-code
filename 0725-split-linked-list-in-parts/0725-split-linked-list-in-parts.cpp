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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        vector<ListNode*> res(k, nullptr);
        ListNode* curr = head, * save = nullptr;
        while(curr){
            curr = curr->next, len++;
        }
        curr = head;
        int comp_len = len / k, rem = len % k, ind = 0;
        while(curr){
            int t = comp_len + (rem > 0 ? 1 : 0);
            rem--;
            res[ind] = curr, ind++;
            while(t-- > 1){
                curr = curr->next;
            }
            save = curr->next, curr->next = nullptr;
            curr = save;
        }
        return res;
    }
};