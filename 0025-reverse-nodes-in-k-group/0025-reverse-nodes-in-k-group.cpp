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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        
        auto prev = dummy, curr = dummy, nxt = dummy;
        
        int cnt = 0;
        
        while(curr && curr->next){
            cnt++;
            curr = curr->next;
        }
        
        while(cnt>=k){
            curr = prev->next;
            nxt = curr->next;
            
            for(int i=1;i<k;i++){
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
            cnt = cnt - k;
        }
        
        return dummy->next;
    }
};