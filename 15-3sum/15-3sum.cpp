class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        
        for(int i = 0;i<nums.size();i++){
            
            if((i>0) && nums[i] == nums[i-1])
                continue;
            
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum > 0)
                    r--;
                else if (sum < 0 ){
                    l++;
                }else{
                    
                    ans.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    
                    while(l<r && nums[l+1] == nums[l]) l++;
                    while(l<r && nums[r-1] == nums[r]) r--;
                    
                    l++;
                    r--;
                }
            }
            
        }
        
        return ans;
    }
};