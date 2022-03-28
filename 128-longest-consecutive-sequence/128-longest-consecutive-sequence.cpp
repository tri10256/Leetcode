class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
            return 0;
        if(nums.size() == 1)
            return 1;
        
        int ans = 1;
        
        int count = 1;
        
        for(int i = 1;i<nums.size();i++){
            if(nums[i] - nums[i-1] == 1){
                ++count;
                ans = max(count,ans);
            }else if(nums[i] - nums[i-1] == 0){
                ans = max(count,ans);
            }else{
                count = 1;
            }
        }
        
        return ans ;
    }
};