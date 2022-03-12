/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    /*  A->A'->B->B'->C->C'->D->D' ,  A'->B'->C'->D' */
    
    Node* copyRandomList(Node* head) {
        
        Node *curr = head;
        
        while(curr){
           Node *list = curr->next;
           curr->next = new Node(curr->val);
           curr->next->next = list;
           curr = curr->next->next;
           curr = list;
        }
        
        curr = head;
        
        while(curr){
          Node *list = curr->next->next;
          if(curr->random){
            Node *curam = curr->random;
            curr->next->random = curam->next;
          }
         curr = list;
        }
        
        Node* ans = new Node(0);
        Node*helper = ans;
        
        while(head){
            //To make ans
            helper->next = head->next;
            helper = helper->next;
            
            //To restore head
            head->next  = head->next->next;
            head = head->next;
        }
        
       
        
        return ans->next;
           
    }
};