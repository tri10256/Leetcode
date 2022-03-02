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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>num1;
        stack<int>num2;
        
        ListNode *curr = l1;
        while(curr){
            num1.push(curr->val);
            curr = curr->next;
            
        }
        
         curr = l2;
        while(curr){
            num2.push(curr->val);
            curr = curr->next;
        }
        
       
        stack<int>ans;
        
            int carry = 0; 
            while(!num1.empty() && !num2.empty()){
                
                int digit1 = num1.top();
                num1.pop();
                int digit2 = num2.top();
                num2.pop();
                
                int sum = digit1+digit2 + carry;
                if(sum>9)
                {
                    carry = 1;
                    ans.push(sum%10);
                }else{
                    carry = 0;
                    ans.push(sum);
                }
            }
        while(!num1.empty()){
            int digit = num1.top();
            num1.pop();
            int sum = digit+carry;
            if(sum>9)
                {
                    carry = 1;
                    ans.push(sum%10);
                }else{
                    carry = 0;
                    ans.push(sum);
                }
        }
        while(!num2.empty()){
            int digit = num2.top();
            num2.pop();
            int sum = digit+carry;
            if(sum>9)
                {
                    carry = 1;
                    ans.push(sum%10);
                }else{
                    carry = 0;
                    ans.push(sum);
                }
        }
        
        if(carry != 0)
            ans.push(carry);
        
        ListNode *head = NULL;
        while(!ans.empty()){
          if(!head){
              head = new ListNode(ans.top());
              ans.pop();
          }else{
              ListNode *curr = head;
              while(curr->next)
                  curr = curr->next;
              curr->next = new ListNode(ans.top());
              ans.pop();
          }
        }
        
        
        return head;    
    }
};