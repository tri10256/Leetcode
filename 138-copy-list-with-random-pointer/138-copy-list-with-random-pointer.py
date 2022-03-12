"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
from collections import defaultdict
class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if(head == None):
            return head
        Map = defaultdict()
        curr = head
        while(curr):
            node = Node(curr.val)
            Map[curr] = node
            curr = curr.next
        
        curr = head
        
        while(curr):
            node = Map[curr]
            if(curr.next != None):
                node.next = Map[curr.next]
            if(curr.random != None):
                node.random = Map[curr.random]
            curr = curr.next
            
        curr = head
        
        return Map[curr]
        
        