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
    
    vector<int>helper(TreeNode *root,int k,int &count){
        if(!root)
            return {0};
        if(!root->left && !root->right)
            return {1};
        
        vector<int>leftdis = helper(root->left,k,count);
        vector<int>rightdis = helper(root->right,k,count);
        
        for(auto &x:leftdis){
            for(auto &y:rightdis){
                if(x > 0 && y> 0 && x+y<=k){
                    count++;
                }
            }
        }
        
        vector<int>ans;
        for(auto &x:leftdis){
            if(x>0 && x<k){
                ans.push_back(x+1);
            }
        }
        
        for(auto &y:rightdis){
            if(y>0 && y<k){
                ans.push_back(y+1);
            }
        }
        
        return ans;
    }
    
    int countPairs(TreeNode* root, int distance) {
        
        int count = 0;
        vector<int>vec = helper(root,distance,count);
        
        return count;
    }
};