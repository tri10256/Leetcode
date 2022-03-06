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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>parent;
        unordered_map<int,bool>ischild;
        
        for(auto v:descriptions){
            if(!parent.count(v[0])){
                TreeNode *par = new TreeNode(v[0]);
                parent[v[0]] = par;
            }
            
            if(!parent.count(v[1])){
                TreeNode *child = new TreeNode(v[1]);
                parent[v[1]] = child;
            }
            
            if(v[2] == 1)
                parent[v[0]]->left = parent[v[1]];
            else
                parent[v[0]]->right = parent[v[1]];
            
            ischild[v[1]] = true;
        }
        
        TreeNode *ans = NULL;
        for(auto v:descriptions){
            if(!ischild[v[0]])
                ans = parent[v[0]];
        }
        
        return ans;
    }
};