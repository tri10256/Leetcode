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
        int carry=0;
        ListNode *node=NULL;
        ListNode * prev=NULL;
        ListNode *temp1=l1;
        ListNode *temp2=l2;
        while(temp1!=NULL && temp2!=NULL )
        {
            int data=temp1->val+temp2->val+carry;
            if(data>=10)
            {
                carry=1;
                int digit=data%10;
                ListNode *nai=new ListNode(digit);
                if(node==NULL)
                {
                    node=nai;    
                }
                else
                {
                    ListNode *last=node;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=nai;
                }
            }
            else
            {
                carry=0;
                int digit=data%10;
                ListNode *nai=new ListNode(digit);
                //cout<<nai->val<<endl;
                //node->next=nai;
                 if(node==NULL)
                {
                    node=nai;    
                }
                else
                {
                    ListNode *last=node;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=nai;
                }
                
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL)
        {
             int data=temp1->val+carry;
             if(data>=10)
            {
                carry=1;
                int digit=data%10;
                 ListNode *nai=new ListNode(digit);
                if(node==NULL)
                {
                    node=nai;    
                }
                else
                {
                    ListNode *last=node;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=nai;
                }
            }
            else
            {
                carry=0;
                int digit=data%10;
                 ListNode *nai=new ListNode(digit);
                if(node==NULL)
                {
                    node=nai;    
                }
                else
                {
                    ListNode *last=node;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=nai;
                }
           }
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
             int data=temp2->val+carry;
             if(data>=10)
            {
                carry=1;
                int digit=data%10;
                ListNode *nai=new ListNode(digit);
                 if(node==NULL)
                {
                    node=nai;    
                }
                else
                {
                    ListNode *last=node;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=nai;
                }
            }
            else
            {
                carry=0;
                int digit=data%10;
                ListNode *nai=new ListNode(digit);
                 if(node==NULL)
                {
                    node=nai;    
                }
                else
                {
                    ListNode *last=node;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=nai;
                }
                
            }
            temp2=temp2->next;
        }
        if(carry!=0)
        {
                ListNode *nai=new ListNode(carry);
                carry=0;
                 if(node==NULL)
                {
                    node=nai;    
                }
                else
                {
                    ListNode *last=node;
                    while(last->next!=NULL)
                        last=last->next;
                    last->next=nai;
                }
        }
       
       return node;
    }
};