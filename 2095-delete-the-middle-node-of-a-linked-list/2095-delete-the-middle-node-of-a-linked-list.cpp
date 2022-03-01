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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        if(!fast->next)
            return NULL;
        
        while(fast->next && fast->next->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(!fast->next){
        ListNode *next = slow->next;
        prev->next = next;
        }else if(!fast->next->next){
            ListNode *next = slow->next->next;
            slow->next = next;
        }   
        
        return head;
    }
};