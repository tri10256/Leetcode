class Solution {
public:
    
   unordered_map<int,int>cache;
    
    int money_theft(vector<int>&nums,int i){
        
        if(i == 0)
            return nums[0];
        if(i == 1)
            return max(nums[0],nums[1]);
        
        if(cache.count(i))
            return cache[i];
         
        int theft = money_theft(nums,i-2) + nums[i];
        int notheft = money_theft(nums,i-1);
        
        return cache[i] = max(notheft,theft);
    }
    
    
    int rob(vector<int>& nums) {
      int n = nums.size();   
    //  memset(cache,-1,sizeof(cache));
        return money_theft(nums,n-1);
    }
};