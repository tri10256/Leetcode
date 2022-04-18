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
    vector<int>inorder(TreeNode *root,vector<int>&temp){
      if(root == NULL)
          return temp;
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
        return temp;
    }
    int kthSmallest(TreeNode* root, int k) {
      vector<int>temp;
      vector<int>nums = inorder(root,temp);
      for(auto num:nums)
          cout<<num<<" ";
       return nums[k-1];
    }
};