class Solution {
public:
    
    void dfs(int s, vector<int>adj[],vector<vector<int>>&ans,vector<int>&temp,int n){
        
        temp.push_back(s);
    
        if(s==n-1){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        for(auto v:adj[s]){
            dfs(v,adj,ans,temp,n);
        }
        
        if(temp.size()>0)
            
        temp.pop_back();
        
}
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>&graph) {
        
        int n=graph.size();
        vector<int>adj[n+1];
        
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
               adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<vector<int>>ans;
        vector<int>temp;
        
        dfs(0,adj,ans,temp,n);
        
        return ans;
        
    }
};