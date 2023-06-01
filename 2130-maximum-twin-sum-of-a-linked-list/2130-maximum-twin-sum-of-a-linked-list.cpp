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
    
    int pairSum(ListNode* head) {
        int count = 0;
        ListNode *slow = head, *fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* dummy = NULL;
        while(slow){
            ListNode* temp = slow->next;
            slow->next = dummy;
            dummy = slow;
            slow = temp;
        }
        
        
        while(dummy){
            int curr_num = head->val + dummy->val;
            count = max(count, curr_num);
            dummy = dummy->next;
            head = head->next;
        }
        
        return count;
    }
};