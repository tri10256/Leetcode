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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
     TreeNode* partition(ListNode *head){
         if(!head)
             return NULL;
         if(head->next==NULL){
             TreeNode *l = new TreeNode(head->val);
             return l;
         }
         if(head->next->next == NULL){
             TreeNode *temphead = new TreeNode(head->next->val);
             TreeNode *templeft = new TreeNode(head->val);
             temphead->left = templeft;
             return temphead;
         }
        
        ListNode *leftlist = head;
        ListNode *rightlist = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
         
        prev->next = NULL;
        leftlist   = head;
        rightlist  = slow->next;
       
        TreeNode *tree = new TreeNode(slow->val);
        tree->left     = partition(leftlist);
        tree->right    = partition(rightlist);
        
        return tree;
    }
    
    TreeNode* sortedListToBST(ListNode* head) { 
        return partition(head);  
    }
};