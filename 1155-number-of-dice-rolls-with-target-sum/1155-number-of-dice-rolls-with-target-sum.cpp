class Solution {
public:
    int dp[31][1001];
    int solve(int n, int k , int target,int sum){
        if(n==1){
            for(int i = 1;i<=k;i++){
                if(sum+i == target)
                    return 1;       
            }
            return  0;
        }
        
        if(dp[n][sum] != -1)
            return dp[n][sum];
        
        int ans = 0;
        for(int i = 1;i<=k;i++){
            ans  =(ans+ solve(n-1,k,target,sum+i))%1000000007;    
        }
          
        return dp[n][sum]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
       
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target,0);
    }
};