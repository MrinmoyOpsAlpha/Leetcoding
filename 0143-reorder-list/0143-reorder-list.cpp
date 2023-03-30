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
    ListNode* middleNode(ListNode* head) {
        auto slow = head, fast = head;
        while(fast && fast -> next)
            slow = slow -> next,
            fast = fast -> next -> next;            
        return slow;                                
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head){
            auto temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        
        auto mid = middleNode(head);
        auto R = reverseList(mid);
        auto L = head -> next;

        for(int i = 0; L != R; i++)    
        {
            if(i & 1) {                              
                head -> next = L;
                L = L -> next;
            }
            else {
                head -> next = R;
                R = R -> next;
            }
            
            head = head -> next;
        }
    }
};