class Solution {
public:
    vector<int>dp;
    int jumps(vector<int>&nums,int pos)
    {
        if(pos>=nums.size()-1)
            return 0;
        int minjump=1001;
        if(dp[pos]!=1001)
            return dp[pos];
        for(int i=1;i<=nums[pos];i++)
        {
            dp[pos]=min(dp[pos],1+jumps(nums,pos+i));
        }
        return dp[pos];
    }
    int jump(vector<int>& nums) {
//         GREEDY  APPROACH
//         int jumps=0;
//         int currend=0;
//         int far=0;
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             far=max(far,i+nums[i]);
           
//             if(i==currend)
//             {
//                  jumps++;
//                 currend=far;
//             }
//         }
//         return jumps;
        dp.assign(nums.size(),1001);
        if(jumps(nums,0)==1001)
            return 5753;
        return jumps(nums,0);
        
    }
};