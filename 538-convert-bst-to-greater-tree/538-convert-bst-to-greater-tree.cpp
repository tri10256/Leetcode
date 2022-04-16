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

int x = 0;
void func(TreeNode *root)
{
    if(root == NULL) return;
    
    func(root->right);
    root->val = root->val + x;
    x = root->val;
    func(root->left);
}

TreeNode* convertBST(TreeNode* root) 
{
    func(root);
    return root;
}
};