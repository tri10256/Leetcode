class Solution {
public:
    int dp[1005][10005];
    int recur(vector<int>&nums,vector<int>&multipliers,int i ,int left){
        if(i == multipliers.size())
            return 0;
        
        if(dp[i][left]!=-1)
            return dp[i][left];
        
        int ans1 = nums[left]*multipliers[i] + recur(nums,multipliers,i+1,left+1); 
        int right = nums.size() - 1 - (i - left); 
        int ans2 = nums[right]*multipliers[i] + recur(nums,multipliers,i+1,left);
        
        return dp[i][left] = max(ans1,ans2);
       // return max(ans1,ans2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size();
        int m = multipliers.size();
        
        memset(dp,-1,sizeof(dp));
        
        return recur(nums,multipliers,0,0);
    }
};