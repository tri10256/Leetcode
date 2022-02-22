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
    unordered_map<int,vector<int>>graph;
    
    void inorder(TreeNode *root){
        if(!root)
            return;
        
        if(root->left){
            
        graph[root->val].push_back(root->left->val);
        graph[root->left->val].push_back(root->val);   
        }
        
        if(root->right){
            
             graph[root->val].push_back(root->right->val);
             graph[root->right->val].push_back(root->val);   
        }
        
        
        inorder(root->left);
        inorder(root->right);
    }
    
    
    unordered_map<int,int>dist;
    vector<int>ans;
    
    void bfs(int target_val,int k){
        
        
        queue<int>q;
        q.push(target_val);
        
        //int n = graph.size();
        //cout<<n;
        vector<int>vis(502,0);
         
        while(!q.empty()){
            
            int u = q.front();
             q.pop();
            
            vis[u] = 1;
              
            auto nei = graph[u];

            for(int i = 0;i<nei.size();i++){
                
                 int v = nei[i];
                
                if(!vis[v]){
                    
                  dist[v] = dist[u] +1;
                    
                  if(dist[v]==k){
                      ans.push_back(v);
                  }
                  q.push(v); 
                }
            } 
        }
           
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        
        if(k==0)
            ans.push_back(target->val);
        
       inorder(root);
        
        // for(auto u:graph){
        //     auto vec = u.second;
        //     cout<<u.first;
        //     cout<<"->";
        //     for(int i =0;i<vec.size();i++){
        //         cout<<vec[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        //cout<<target->val;
        
        bfs(target->val,k);
        
        // for(auto u:ans){
        //     cout<<u<<" ";
        // }
        
       
       return ans;
    }
};