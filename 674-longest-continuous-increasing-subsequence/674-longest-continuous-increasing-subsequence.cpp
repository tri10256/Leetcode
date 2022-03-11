class Solution {
public:
    int ans = INT_MIN;
    void recur(vector<int>&nums,int i,int j,int len){
        if(i>=nums.size()){
            ans = max(ans,len);
            return ;
        }
       
        if(nums[i]>nums[j]){
            len++;
            recur(nums,i+1,i,len);
        }else{
            ans = max(len,ans);
            len = 0;
            recur(nums,i+1,i,len);
        }  
    }
    int findLengthOfLCIS(vector<int>& nums) {
        recur(nums,0,0,0);
        return ans+1;
    }
};