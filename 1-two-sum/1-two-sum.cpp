class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,int>>map;
        for(int i = 0;i<nums.size();i++)
            map[nums[i]] = {nums[i],i};
        
        for(int i = 0;i<nums.size();i++){
            if(map.count(target - nums[i]) && i!=map[target-nums[i]].second){
                return {i,map[target-nums[i]].second};
            }
        }
        
        return {};
    }
};