class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int i, int j, int n, int m, string &str)
    {
         if(i<0 || j<0 || i>=n || j>=m || visited[i][j]!=-1 || grid[i][j]=='0' )
            return;
          visited[i][j]=0;
          str.push_back(grid[i][j]);
        
          dfs(grid,visited,i-1,j,n,m,str);
          dfs(grid,visited,i,j+1,n,m,str);
          dfs(grid,visited,i+1,j,n,m,str);
          dfs(grid,visited,i,j-1,n,m,str);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<string>st;
         vector<vector<int>>visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               
                string str="";
                dfs(grid,visited,i,j,n,m,str);
                if(visited[i][j]!=-1&& str.size()>0)
                    st.push_back(str);
                
            }
        }
        return st.size();
    }
};