class Solution {
public:
    
    int dirx[4] = {1,0,-1,0};
    int diry[4] = {0,-1,0,1};
    
    void dfs(vector<vector<char>>&board,vector<vector<int>>&visited,int i, int j, int n, int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O' )
            return;
        
        board[i][j]='1';
        
        for(int k = 0;k<4;k++){
            int nx = i + dirx[k];
            int ny = j + diry[k];
            dfs(board,visited,nx,ny,n,m);
        }
        
    }
    void solve(vector<vector<char>>& board) {
         int n=board.size();
        int m=board[0].size();
        if(n<=2 || m<=2)
            return;
        vector<vector<int>>visited(n,vector<int>(m,-1));
       
            for(int j=0;j<m;j++)
            {
                dfs(board,visited,0,j,n,m);
            }
            for(int j=0;j<m;j++)
            {
                dfs(board,visited,n-1,j,n,m);
            }
            for(int i=0;i<n;i++)
            {
                dfs(board,visited,i,0,n,m);
            }
            for(int i=0;i<n;i++)
            {
                dfs(board,visited,i,m-1,n,m);
            }
           
                
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(board[i][j]!='1')
                    board[i][j]='X';
                    else if(board[i][j]=='1')
                        board[i][j]='O';
                }
            }
        
    }
};