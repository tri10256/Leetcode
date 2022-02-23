/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*,Node*>hashmap;
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
       if(hashmap.count(node)) 
            return hashmap[node];
        
        Node *newnode= new Node(node->val);
        hashmap[node]=newnode;
        for(auto neighbour:node->neighbors){
            newnode->neighbors.push_back(cloneGraph(neighbour)); 
        }
        return newnode;
        
    }
};