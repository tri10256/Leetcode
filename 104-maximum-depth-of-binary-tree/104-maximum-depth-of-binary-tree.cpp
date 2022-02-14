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
    int dfs(TreeNode *root)
    {
        if(!root)
            return 0;
        
        int left=1+dfs(root->left);
        int right=1+dfs(root->right);
        
        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return dfs(root);
        
    }
};