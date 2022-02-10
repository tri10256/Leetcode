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
  
//     void postorder(TreeNode *root,vector<int>&ans){
//         if(!root)
//         return;
//        postorder(root->left,ans);
//        postorder(root->right,ans);
        
//       ans.push_back(root->val);
//     }
    
    void post(TreeNode *root,vector<int>&ans){
        
        if(!root)
            return;
        
       stack<TreeNode*>main;
       stack<TreeNode*>alt;
       main.push(root);
        
        while(!main.empty()){
            TreeNode *node = main.top();
            main.pop();
            alt.push(node);
            
            if(node->left)
                main.push(node->left);
            if(node->right)
                main.push(node->right);
        }
        
        while(!alt.empty()){
            ans.push_back(alt.top()->val);
            alt.pop();
        }
        
       
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
          
        post(root,ans);
        return ans;
    }
};