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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(), *right =  new ListNode();
        ListNode *ltail = left, *rtail = right;
        while(head){
            if(head->val < x){
                ltail->next = head;
                ltail = ltail->next;
            }
            else{
                rtail->next = head;
                rtail = rtail->next;
            }
            head = head->next;
        }
        
        ltail->next = right->next;
        rtail->next = NULL;
        return left->next;
    }
};