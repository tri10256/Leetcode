class Solution {
public:
    
    bool check(int mid,vector<int>&nums,int m){
        int curr_sum = 0;
        int cnt = 0;
        int n = nums.size();
        
        for(int i = 0;i<n;i++){
            if(nums[i] > mid)
                return false;
            if(curr_sum + nums[i] <= mid){
                curr_sum+=nums[i];
            }else{
                cnt++;
                curr_sum = nums[i];
            }
        }
        
        cnt++;
        
       return cnt<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int l = 0;
        int r = 1e9+1;
        
        while(l<r){
            int mid = l+(r-l)/2;
            
            if(check(mid,nums,m)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return l;
    }
};