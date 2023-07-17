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

    ListNode* reverse(ListNode* head){
        ListNode* newHead = NULL;
        while(head){
            auto temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
    
    ListNode* helper(ListNode* l1, ListNode* l2){
        ListNode* dummyHead = new ListNode();
        ListNode* tail = dummyHead;
        int carry = 0;
        
        while(l1 || l2 || carry){
            int digit1 = (l1) ?  l1->val:0;
            int digit2 = (l2) ?  l2->val:0;
            
            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum/10;
            
            tail->next = new ListNode(digit);
            tail = tail->next;
            
            l1 = (l1) ? l1->next:nullptr;
            l2 = (l2) ? l2->next:nullptr;
        }
        return dummyHead->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = helper(l1,l2);
        return reverse(ans);
    }
};