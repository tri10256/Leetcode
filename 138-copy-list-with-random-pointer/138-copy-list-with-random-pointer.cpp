/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {   next = NULL;
     
        val = _val;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>map;
        
        Node*curr = head;
        while(curr){
            map[curr] = new Node(curr->val);
            curr= curr->next;
        }
         
        curr = head;
        while(curr){
            
            Node *nai = map[curr];
            nai->next = map[curr->next];
            nai ->random = map[curr->random];
             
            curr= curr->next;
        }
        
        curr = head;
        
        return map[curr];
    }
};