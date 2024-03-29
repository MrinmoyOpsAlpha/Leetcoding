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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        
        int length = 1;
        auto tail = head;
        
        while(tail && tail->next){
            tail = tail->next;
            length++;
        }
        
        tail->next = head;
        ListNode* curr = new ListNode();
        
        if(k = k % length){
            for(int i=0;i<length-k;i++){
                tail = tail->next;
            }
        }
        
        curr->next = tail->next;
        tail->next = NULL;
        
        return curr->next;
    }
};