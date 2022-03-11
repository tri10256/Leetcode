class Solution {
public:
    /*
     [0,0,0,0]
     [0,1,0,0]
     [0,0,0,0]
     [0,0,1,0]
     [0,0,0,0]
    */
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>&Grid,int n,int m,int i ,int j){
        if(i< 0 || j< 0 || i>=n || j>=m || Grid[i][j] == 1)
            return 0;
        
        if(i == n-1 && j == m-1)
            return 1;
        
        if(dp[i][j] != -1)
            return  dp[i][j];
        
        int ans1 = 0;
        int ans2 = 0;
        
        if(i+1<n)
         ans1 = dfs(Grid,n,m,i+1,j);
        if(j+1<m)
        ans2 = dfs(Grid,n,m,i,j+1);
        
        return dp[i][j] = ans1+ans2;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>&Grid) {
        int n = Grid.size();
        int m = Grid[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        
        if(n ==1){
            for(int j = 0;j<m;j++){
                if(Grid[0][j] == 1)
                    return 0;
            }
         
            return 1;
        }
        
         if(m ==1){
            for(int i = 0;i<n;i++){
                if(Grid[i][0] == 1)
                    return 0;
            }
         
            return 1;
        }
        
        
        
        return dfs(Grid,n,m,0,0);
        
    }
};