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
    ListNode* reverse(ListNode* head){
        ListNode* newHead = NULL;
        while(head){
            ListNode* temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        
        while(slow){
            if(slow->val!=head->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};