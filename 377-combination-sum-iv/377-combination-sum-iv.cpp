class Solution {
public:
    vector<vector<int>>dp;
    int nocomb(int sum,int j,int target,vector<int>&nums)
    { 
           if(sum>target)
                return 0;
           if(sum == target){
               return 1;
           }
         if(dp[sum][j] != -1)
             return dp[sum][j];
        
        int count = 0;
            for(auto i = 0;i<nums.size();i++)
            { 
                sum+=nums[i];
                count += nocomb(sum,i,target,nums);
                sum -=nums[i];
            }
        
        return dp[sum][j] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        dp.resize(1001,vector<int>(201,-1));
        return nocomb(0,0,target,nums);
    }
};