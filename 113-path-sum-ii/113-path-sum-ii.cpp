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
    vector<vector<int>>res;
    void recur(TreeNode *head  ,int target,int sum,vector<int>path){
        
        if(!head)
            return;
        sum +=head->val;
        path.push_back(head->val);
        if(!head->left && !head->right && sum == target){
            res.push_back(path);
            return;
        }
        
        recur(head->left,target,sum,path);
        recur(head->right,target,sum,path);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        recur(root,targetSum,0,{});
        return res;
    }
};