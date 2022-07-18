/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool findPath(TreeNode *root,TreeNode *k,vector<TreeNode*>&path){
        if(!root)
            return false;
        
        path.push_back(root);
        if(root == k)
            return true;
        
        if((root->left && findPath(root->left,k,path)) || (root->right && findPath(root->right,k,path)))
            return true;
        
        path.pop_back();
        
        
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;
        
        if(!findPath(root,p,path1) || !findPath(root,q,path2))
            return new TreeNode(-1);
        
        int i;
        
        for(i = 0;i<path1.size() && i< path2.size();++i){
            if(path1[i] != path2[i])
                break;
        }
        
      return path1[i-1];
    }
};