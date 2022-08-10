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

TreeNode * rec(vector<int>&nums,int start ,int end){ 
    if(start>end)
        return NULL;
    
    
    TreeNode *head = new TreeNode();
    
    if(start<=end){
    int mid = (start + end)/2;
    head->val = nums[mid];
    head->left = rec(nums,start,mid-1);
    head->right = rec(nums,mid+1,end);}
    
    return head;
}


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0)
            return NULL;
        if(n==1)
            return (new TreeNode(nums[0]));
        
//         int mid = n/2;
        
//         TreeNode *head = new TreeNode(nums[mid]);
        
//         vector<int>left_nums(nums.begin(),nums.begin()+mid);
//         vector<int>right_nums(nums.begin()+mid+1 , nums.end());
        
        
//         TreeNode *leftans = sortedArrayToBST(left_nums);
//         TreeNode* rightans = sortedArrayToBST(right_nums);
        
//         head->left = leftans;
//         head ->right = rightans;
        
        return rec(nums,0,nums.size()-1);
        
  
    }
};