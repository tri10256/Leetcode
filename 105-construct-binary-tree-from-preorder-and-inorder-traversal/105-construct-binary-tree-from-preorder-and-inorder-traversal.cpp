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
    int fun(vector<int>&preorder,vector<int>inorder,int j){
        
        int val = preorder[j];
        int index=-1;
        
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==val)
                index = i;
        }
         return index;   
    }
    int i = 0;
     TreeNode *build(vector<int>&nums,vector<int>&preorder,int start,int end){
         
         cout<<i<<" "<<preorder[i]<<" "<<endl;
         
        int idx = fun(preorder,nums,i);
        
        TreeNode *node = new TreeNode(nums[idx]);
      
        cout<<"idx"<<idx<<"start"<<start<<" "<<end<<"end"<<" "<<endl;;
        if(start>end)
            return NULL;
        if(start==end)
            return node;
        
        if(start<idx){
            cout<<"leftcall"<<endl;
            i++;
            node->left = build(nums,preorder,start,idx-1);
        }
         
        if(idx<end){
            cout<<"right call"<<endl;
            i++;
            node->right = build(nums,preorder,idx+1,end);
        }
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        
       return build(inorder,preorder,0,inorder.size()-1);
    }
};