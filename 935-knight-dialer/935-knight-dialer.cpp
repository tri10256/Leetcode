class Solution {
     int row = 4;
     int col = 3;
     int mod = 1e9+7;
public:
    int dp[50001][4][3]= {};
    int dfs(int n,int i, int j){
        if(i<0 || j<0 || i>=row || j>=col || (i == 3 && j == 0) || (i==3 && j==2))
        return 0;
        
        if(n==1){
         return 1;
        }
        
        if(dp[n][i][j]!=0)
        return dp[n][i][j];
      int sum = 0;
        
      sum =(sum%mod + dfs(n-1,i-2,j+1)%mod)%mod;
      sum =(sum%mod + dfs(n-1,i-1,j+2)%mod)%mod;
      sum =(sum%mod + dfs(n-1,i+1,j+2)%mod)%mod;
      sum =(sum%mod + dfs(n-1,i+2,j+1)%mod)%mod;
      sum =(sum%mod + dfs(n-1,i+2,j-1)%mod)%mod;
      sum =(sum%mod + dfs(n-1,i+1,j-2)%mod)%mod;
      sum =(sum%mod + dfs(n-1,i-1,j-2)%mod)%mod;
      sum =(sum%mod + dfs(n-1,i-2,j-1)%mod)%mod;
        
      return dp[n][i][j]=sum%mod;
    }
    int knightDialer(int n) {
        
        int ans = 0;
       
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                   ans = (ans%mod + dfs(n,i,j)%mod)%mod;   
            }
        }
        
        return ans;
        
    }
};