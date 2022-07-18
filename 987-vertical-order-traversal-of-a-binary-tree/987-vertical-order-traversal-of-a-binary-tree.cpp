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
    
    void verticalOrder(TreeNode *root,vector<vector<int>>&ans){
        
        if(!root)
            return;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        q.push({NULL,NULL});
        int HL = 0;
        unordered_map<int,vector<pair<int,int>>>mp;
        int minL = INT_MAX;
        int maxL = INT_MIN;
        
        while(q.size() > 1){
            
            auto node = q.front().first;
            int hd    = q.front().second;
            minL = min(minL,hd);
            maxL = max(maxL,hd);
            
            q.pop();
            
            if(node == NULL){
                HL++;
                q.push({NULL,NULL});
            }else{
                
                mp[hd].push_back({HL,node->val});
                
                if(node->left){
                    q.push({node->left,hd-1});
                }
                if(node->right){
                    q.push({node->right,hd+1});
                }
                
            }
            
        }
        
        for(int i = minL;i<=maxL;++i){
            auto data = mp[i];
            sort(data.begin(),data.end());
            
            vector<int>temp;
            for(auto pai:data){
                temp.push_back(pai.second);
            }
            
            ans.push_back(temp);
            
        }
        
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        verticalOrder(root,ans);
        
        return ans;
    }
};