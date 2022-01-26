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
    void push_left(stack<TreeNode*>&st,TreeNode *n){
        while(n){
            st.push(n);
            n = n->left;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        vector<int>ans;
        
        push_left(st1,root1);
        push_left(st2,root2);
        
        while(!st1.empty() || !st2.empty()){
            stack<TreeNode*>&st = st1.empty()?st2:st2.empty()?st1:st1.top()->val<st2.top()->val?st1:st2;
            ans.push_back(st.top()->val);
        
            auto n = st.top();
            st.pop();
            n = n->right;
            
            push_left(st,n);
        }
        
        return ans;
    }
};