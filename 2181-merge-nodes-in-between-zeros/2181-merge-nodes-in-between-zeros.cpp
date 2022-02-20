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
    ListNode* mergeNodes(ListNode* head) {
         
        ListNode *curr = head;
        ListNode *second = NULL;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
         
        while(curr!=NULL && curr->next!=NULL){
            second = curr->next;
            int sum = 0;
            
            while(second->val != 0){
                sum+=second->val;
                second=second->next;
            }
            
            ListNode *temp = new ListNode(sum);
            tail->next = temp;
            tail = temp;
            
            curr=second;   
        }
        
        return dummy->next;
    }
};