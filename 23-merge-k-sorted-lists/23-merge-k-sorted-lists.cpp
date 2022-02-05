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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val>=l2->val) l2->next = merge(l1, l2-> next);
        else{
            l1->next = merge(l1->next, l2);
            l2 = l1;
        }
        
        return l2;
    }
    
    ListNode* divide(vector<ListNode*>lists,int s, int e){
        if(s>e)
            return NULL;
        if(s==e)
            return lists[s];
        
        int mid = s+(e-s)/2;
        
        ListNode *list1 = divide(lists,s,mid);
        ListNode *list2 = divide(lists,mid+1,e);
        
        return merge(list1,list2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divide(lists,0,lists.size()-1);
    }
};