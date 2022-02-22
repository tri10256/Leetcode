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
    
    int bfs(TreeNode *root){
        if(!root)
            return 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
       
        vector<int>temp;
        while(q.size()>1){
            TreeNode *node = q.front();
            q.pop();
            if(node == NULL){
                temp.clear();
                q.push(NULL);
            }else{
            temp.push_back(node->val);
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
            }
        }
       
        int sum = 0;
        for(auto val:temp){
            sum+=val;
        }
        
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
     
       return bfs(root);
    }
};