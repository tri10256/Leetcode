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
    ListNode *detectCycle(ListNode *head) {
        
        
        if(!head)
            return NULL;
        if(!head->next)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        
        while(fast!=NULL && fast->next!=NULL && slow->next!=fast->next->next){
               
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(!fast || !fast->next)
            return NULL;
        
       
        fast = fast->next->next;
        slow = slow->next;
        
        slow= head;
        while(slow!=fast){
            
            slow=slow->next;
            fast=fast->next;
        }
        
        if(slow==fast)
            return slow;
        
        return NULL;
    }
};