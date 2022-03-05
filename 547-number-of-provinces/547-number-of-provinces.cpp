class Solution {
public:
    void dfs(int s,vector<int>adj[],vector<int>&visited){
        
        if(visited[s])
            return;
        visited[s]=1;
        
        for(auto v:adj[s]){
            dfs(v,adj,visited);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<int>adj[n+2];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        vector<int>visited(n+2,0);
        
        int count=0;
        
        for(int i=1;i<=n;i++){
            
            if(!visited[i])
            {    
               dfs(i,adj,visited);
                count++;
            }
            
        }
        
        return count;
        
    }
};