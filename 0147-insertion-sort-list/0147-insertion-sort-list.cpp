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
    ListNode* insertionSortList(ListNode* head) {
        for(auto curr = head;curr;curr = curr->next){
            for(auto j=head; j!=curr; j=j->next){
                if(j->val > curr->val){
                    swap(j->val,curr->val);
                }
            }
        }
        
        return head;
    }
};