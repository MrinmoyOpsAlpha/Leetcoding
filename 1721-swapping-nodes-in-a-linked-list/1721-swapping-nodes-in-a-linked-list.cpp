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
    ListNode* swapNodes(ListNode* head, int k) {
        auto temp = head, slow = head, fast = head;
        
        int cnt = 0;
        while(temp){
            cnt++, temp = temp->next;
        }
        
        ListNode *slowPrev = nullptr, *fastPrev = nullptr;
        
        for(int i=1;i<k ;i++){
            slowPrev = slow;
            slow=slow->next;
        }
        
        for(int i=1;i<cnt-k+1;i++){
            fastPrev = fast;
            fast=fast->next;
        }
        
        if(slowPrev) slowPrev->next = fast;
        else head = fast;
        if(fastPrev) fastPrev->next = slow;
        else head = slow;
        
        auto tempNext = slow->next;
        slow->next = fast->next;
        fast->next = tempNext;
        
        
        return head;
    }
};