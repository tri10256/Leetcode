class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<nums.size();i++){
        
            if( i>0 && nums[i-1] == nums[i])
                continue;
            
            for( int j = i+1;j<nums.size();j++){
                
                 if( j> i+1 && nums[j-1] == nums[j])
                 continue;
                
               int l = j+1;
               int r = nums.size()-1;
                
               while(l<r){
                   
               long long int sum = nums[i] + nums[j];
                   sum+=nums[l]+ nums[r];
                
                if(sum > target)
                    r--;
                else if (sum < target ){
                    l++;
                }else{
                    
                ans.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                    
                    ///skip for all the repeating 
                    while(l<r && nums[l+1] == nums[l]) l++;
                    while(l<r && nums[r-1] == nums[r]) r--;
                    
                    l++;
                    r--;
                }
               }
            }
        }
        
        
        return ans; 
    }
};