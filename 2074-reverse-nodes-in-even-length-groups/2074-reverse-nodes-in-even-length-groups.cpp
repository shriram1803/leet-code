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
        ListNode* curr = head;
        int n = 0;
        while(curr) curr = curr->next, n++;
        int grp = 1, visited = 0;
        curr = head;
        ListNode* prev = curr;
        // cout<<n<<endl;
        while(curr and curr->next) {
            int t = grp;
            // cout<<(visited + grp)<< " " <<curr->val<< endl;
            // cout<<curr->val<<endl;
            if((grp % 2 and (visited + grp) <= n) or (visited + grp > n and (n - visited)%2 == 1)) {
                while(--t >= 0 and curr) prev = curr, curr = curr->next;
            } else {
                // cout<<curr->val<< " "<<prev->val<< endl;
                // if(visited + grp )
                // if(grp % 2 == 1 and (n - visited) % 2 == 1) continue;
                ListNode* save = prev, * pre = curr, * nxt = nullptr;
                // curr = curr->next;
                while(--t >= 0 and curr) 
                {
                    nxt = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                }
                // nxt = curr->next;
                save->next->next = curr;
                nxt = save->next;
                save->next = prev;
                prev = nxt;
                // curr = pre;
            }
            // if(curr) cout<<curr->val<<endl;
            visited += grp;
            grp += 1;
        }
        
        
        // int t = n - visited;
        // if(t > 1) {
        //     ListNode* save = curr, * pre = curr, * nxt = nullptr;
        //     curr = curr->next;
        //     while(--t >= 0 and curr) 
        //     {
        //         nxt = curr->next;
        //         curr->next = pre;
        //         pre = curr;
        //         curr = nxt;
        //     }
        //     // nxt = curr->next;
        //     save->next->next = curr;
        //     save->next = pre;
        // }
        
        return head;
    }
};