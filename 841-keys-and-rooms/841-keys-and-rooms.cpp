class Solution {
public:
    void dfs(int s,vector<int>adj[], vector<int>&vis){
        if(vis[s])
            return;
        vis[s]=true;
        for(auto v:adj[s]){
            dfs(v,adj,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        
        vector<int>adj[n+1];
        
        vector<int>visited(n+1,0);
        
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        
        dfs(0,adj,visited);
        
        for(int i=0;i<n;i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};