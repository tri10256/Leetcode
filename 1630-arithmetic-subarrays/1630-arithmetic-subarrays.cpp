class Solution {
public:
    
    
    bool can(vector<int>nums,int l, int r){
        sort(nums.begin()+l,nums.begin()+r+1); 
        int cdiff = nums[l+1] - nums[l];
        
        for(int i = l+1;i<=r;i++){
            int diff = nums[i] - nums[i-1];
            if(diff != cdiff)
                return false;
        }
        
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool>ans;
        
        int n = l.size();
        
        for(int i = 0;i<n;i++){
            int left = l[i];
            int right = r[i];
            
            if(can(nums,left,right))
                ans.push_back(true);
            else{
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};