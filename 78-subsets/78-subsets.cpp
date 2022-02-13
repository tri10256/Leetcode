class Solution {
public:
    
    void backtrack(vector<int>&nums,int k, vector<vector<int>>&res,vector<int>subset){        
        if(k==nums.size()){
            res.push_back(subset);
            return;
        }
        
        
        backtrack(nums,k+1,res,subset);
        
        subset.push_back(nums[k]);
        
        backtrack(nums,k+1,res,subset);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>res;
        
        backtrack(nums,0,res,vector<int>());
        
        return res;
    }
};