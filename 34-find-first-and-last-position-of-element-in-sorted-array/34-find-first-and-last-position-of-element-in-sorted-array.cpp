class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //lower bound returns position of first occurance if number exists and if not then pos of the number next               //higher 
        //than that
        //upper bound gives the pos of next higher number than the target
        
        if(!nums.size())
            return {-1,-1};
        int n = nums.size();
        
        int first = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int last  = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
       
        if(first < n && last-1 < n ){
            if(nums[first] == target && nums[last - 1] == target)
            return {first,last-1};
        }
        
        return {-1,-1};
    }
};