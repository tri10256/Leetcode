class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ///-4-1,-1,0,1,2
        for(int i = 0;i<nums.size();i++){
            
            if((i>0) && nums[i] == nums[i-1])
                continue;
            
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                
                int sum = nums[i] + nums[l] + nums[r];
                
                if(sum == 0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    
                    while(l<r && nums[l+1]==nums[l]){
                        l++;
                        continue;
                    }
                    while(l<r && nums[r-1]==nums[r]){
                        r--;
                        continue;
                    }
                    
                    l++;
                    r--;
                }else if(sum>0){
                    r--;
                }else if(sum<0)
                    l++;
            }
            
        }
        
        return ans;
    }
};