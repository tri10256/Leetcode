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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next )
            return head;
        
       ListNode* nextnext= head->next->next;
        
        ListNode*get=swapPairs(nextnext);
        
        ListNode* nextnode=head->next;
        ListNode*curr=head;
        head=nextnode;
        head->next=curr;
        curr->next=get;
        
        
        return head;
    }
};