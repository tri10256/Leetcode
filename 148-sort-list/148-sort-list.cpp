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
    ListNode *ans  = NULL;
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val>=l2->val) l2->next = mergeTwoLists(l1, l2-> next);
        else{
            l1->next = mergeTwoLists(l1->next, l2);
            l2 = l1;
        }
        return l2;
    }
    void print(ListNode *head){
        
        ListNode *curr = head;
        while(curr){
            cout<<curr->val<<" ";
            curr=curr->next;
        }
    }
    ListNode* divide(ListNode *head){
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *left = NULL;
        ListNode *right = NULL;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        right = slow->next;
        slow->next = NULL;
        left = head;
        
     
        ListNode *l = divide(left);
        ListNode *r = divide(right);
     
     return mergeTwoLists(l,r);
    }
    
    
    ListNode* sortList(ListNode* head) {
        return divide(head);
    }
};