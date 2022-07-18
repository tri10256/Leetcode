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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        //if any one of p and q mathces with root then the root is the LCA
        if(root == p || root == q)
            return  root;
        
    
        TreeNode *left  = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        
        // if we found one node in left and other one in right then the root is LCA
        if(left && right)
            return root;
        
        //if one of them is null then the node in which and tobefound node present will be our LCA
        return left?left:right;
    }
};