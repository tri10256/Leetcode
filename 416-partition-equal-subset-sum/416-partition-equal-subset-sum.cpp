class Solution {
public:
    vector<vector<int>>dp;
    bool isPossible(vector<int>&nums,int i , int target,int sum){
      if(i>=nums.size())
          return false;
      if(sum == target)
          return true;
      bool ans = false;
        
        if(dp[i][sum]!=-1)
            return dp[i][sum];
      
    if(nums[i]<=target)
        ans = isPossible(nums,i+1,target,sum+nums[i]) || isPossible(nums,i+1,target,sum);
    else 
        ans = isPossible(nums,i+1,target,sum);

        return dp[i][sum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum  = 0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2!=0)
            return false;
        
        dp.resize(201,vector<int>(201*101,-1));
        
        return isPossible(nums,0,sum/2,0);
    }
};