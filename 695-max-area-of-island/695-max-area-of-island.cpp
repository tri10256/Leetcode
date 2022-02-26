class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i, int j,int n, int m,int &mxarea, int &area, vector<vector<int>>&visited)
    {
         if(i<0 || j<0 || i>=n || j>=m || visited[i][j]!=-1 || grid[i][j]==0)
            return;
         visited[i][j]=0;
        // cout<<"pre"<<" "<<area<<endl;
         if(grid[i][j]==1)
         area++;
         //cout<<"post" <<" "<<area<<" "<<i<<" " <<j<<" "<<endl;
         mxarea=max(area,mxarea);
         //cout<<"maxarea"<<" "<<mxarea;
         //cout<<endl;
         dfs(grid,i-1,j,n,m,mxarea,area,visited);
         dfs(grid,i,j+1,n,m,mxarea,area,visited);
         dfs(grid,i+1,j,n,m,mxarea,area,visited);
         dfs(grid,i,j-1,n,m,mxarea,area,visited);
         
         
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mxarea=INT_MIN/5;
       
        vector<vector<int>>visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { 
                int area=0;
                dfs(grid,i,j,n,m,mxarea,area,visited);
            }
        }
        return mxarea==INT_MIN/5?0:mxarea;
        
        
    }
};