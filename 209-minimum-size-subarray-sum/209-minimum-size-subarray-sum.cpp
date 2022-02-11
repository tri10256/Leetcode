class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = 0;
        int r = 0;
        int ans = INT_MAX;
        int n = nums.size();
        int sum = 0;
        
        while(r<n){
            sum+=nums[r];
            
            if(sum == target){
                ans = min(ans,r-l+1);
            }else if(sum>target){
                
                while(sum>target){
                    ans = min(ans,r-l+1);
                    sum-=nums[l];
                    l++;
                }
                
                if(sum == target)
                    ans = min(ans,r-l+1);
            }
            
            r++;
        }
        
        
        return ans == INT_MAX?0:ans;
    }
};