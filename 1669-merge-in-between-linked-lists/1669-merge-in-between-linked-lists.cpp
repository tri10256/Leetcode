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
     ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *f=list1,*s=list1;
        for(int i=0;i<a-1;i++) f=f->next;
        
        for(int i=0;i<b;i++) s=s->next;
        
        f->next=list2;
        while(list2->next!=NULL)
            list2=list2->next;
        
        list2->next=s->next;
        return list1;
    }
//     ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
//         ListNode *preva = NULL;
//         ListNode *nextb = NULL;
        
//         for(auto curr = list1;curr && curr->next;curr = curr->next){
//             if(curr->val == a-1){
//                 preva = curr;
//             }
//             if(curr->val == b){
//                 nextb = curr->next;
//             }
//         }
        
//         preva->next = list2;
        
//         ListNode *temp = list1;
//         while(temp && temp->next){
//             cout<<temp->val<<" ";
//             temp = temp->next;
//         }
//         temp->next = nextb;
        
//         return list1;
        
//     }
};