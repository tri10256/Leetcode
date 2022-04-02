class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        
        while(i < n && nums[i] > nums[i-1]) i++;
        
        if(i<n)
        return nums[i];
        
        return nums[0];
    }
};