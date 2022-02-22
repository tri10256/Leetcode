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
    unordered_map<int,vector<pair<int,char>>>graph;
    void preorder(TreeNode *root){
        if(!root)
            return ;
        preorder(root->right);  
            if(root->left){
                graph[root->val].push_back({root->left->val,'L'});
                graph[root->left->val].push_back({root->val,'U'});
            }
          if(root->right){
            graph[root->val].push_back({root->right->val,'R'});
           graph[root->right->val].push_back({root->val,'U'});
          }
         preorder(root->left);
    }

    int vis[100001] = {};
    string ans = "";
    string temp = "";
    void dfs(int &s, int &t){
        vis[s] = 1;
        
        auto nei = graph[s];
        for(int i = 0;i<nei.size();i++){
            
            auto pai = nei[i];
            char path = pai.second;
            int v = pai.first;
            if(v==s)
                ans.clear();
            
            if(!vis[v]){
                ans+=path;
                
                cout<<v<<" ";
                if(v==t){
                    temp = ans;
                    return;
                }
            
                dfs(v,t);
                ans.pop_back();
            }
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        preorder(root);
        dfs(startValue,destValue);
        return temp;
    }
};