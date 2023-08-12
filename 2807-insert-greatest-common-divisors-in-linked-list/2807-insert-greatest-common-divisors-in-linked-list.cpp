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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp && temp->next){
            int val1 = temp->val;
            int val2 = temp->next->val;
            int val3 = __gcd(val1,val2);
            
            ListNode* dummy = new ListNode(val3);
            dummy->next = temp->next;
            temp->next = dummy;
            
            temp=dummy->next;
        }
        
        return head;
    }
};