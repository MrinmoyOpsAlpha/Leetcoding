class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        
        while(head){
            ListNode* temp = head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) return true;
        
        ListNode *slow=head,*fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow=slow->next;
        while(slow){
            if(head->val!=slow->val)  return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};