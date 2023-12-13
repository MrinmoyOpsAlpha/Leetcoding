/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, int> mp;
        
        for(auto p = headA; p != NULL;p=p->next){
            mp[p] = p->val;
        }
        
        for(auto q = headB; q != NULL;q=q->next){
            if(mp.find(q) != mp.end()){
                return q;
            }
        }
        
        return NULL;
    }
};