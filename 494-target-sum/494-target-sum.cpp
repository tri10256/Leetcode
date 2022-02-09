class Solution {
public:
    int dp[1001][1001];
    
    int solve(vector<int>&nums,int target,int sum,int n){
        if(n==0){
            if(sum == target || sum == -target){
                dp[n][abs(sum)] = 1;
                return dp[n][abs(sum)];
            }else{
                dp[n][abs(sum)] = 0;
                return dp[n][abs(sum)];
            }
        }
        
        if(dp[n][abs(sum)]!=-1)
            return dp[n][abs(sum)];
        
         int ans = solve(nums,target,sum+nums[n-1],n-1) + solve(nums,target,sum-nums[n-1],n-1);
        
        return dp[n][abs(sum)]  = ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,target,0,nums.size());
        if(target == 0)
            return ans;
        
        return ans/2;
    }
};