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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,ListNode*> mp;
        
        int sum = 0;
        
        ListNode* dummy = new ListNode(0,head);
        
        auto curr = dummy;
        
        while(curr){
            sum = sum + curr->val;
            
            if(mp.find(sum) != mp.end()){
                curr = mp[sum]->next;
                int p = sum + curr->val;
                
                while( p != sum){
                    mp.erase(p);
                    curr=curr->next;
                    p = p + curr->val;
                }
                
                mp[sum]->next=curr->next;
            }
            else{
                mp[sum] = curr;
            }
            
            curr = curr->next;
        }
        
        return dummy->next;
    }
};