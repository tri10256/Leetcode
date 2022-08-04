class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int>mp;
        for(auto val:nums){
            mp[val]++;
        }
        
        for(auto it:mp){
            
            int n = it.second;
            if(n>1){
                count+=(n*(n-1))/2;
            }
        }
        
        return count;
    }
};