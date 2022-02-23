class Solution {
public:
    int dirx[4] = {1,0,-1,0};
    int diry[4] = {0,-1,0,1};
    
    void dfs1(vector<vector<int>>&grid,int i,int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j])
            return;
        
        
        grid[i][j] = 1;
        
        for(int k = 0 ;k<4;k++){
            int nx = i+dirx[k];
            int ny = j+diry[k];
            dfs1(grid,nx,ny,m,n);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
            for(int j = 0;j<n;j++){
                if(grid[0][j] == 0){
                   dfs1(grid,0,j,m,n);
                }
                if(grid[m-1][j] == 0){
                   dfs1(grid,m-1,j,m,n);
                }
            }
            for(int i = 0;i<m;i++){
                if(grid[i][0] == 0){
                  dfs1(grid,i,0,m,n);
                }
                if(grid[i][n-1] == 0){
                   dfs1(grid,i,n-1,m,n);
                }
            }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 0){
                  dfs1(grid,i,j,m,n);
                    count++;
                }
            }
        }
        
          
    
        return count;
    }
};