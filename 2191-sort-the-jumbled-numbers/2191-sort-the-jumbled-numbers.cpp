class Solution {
public:
    
    int getMapped(int n, vector<int>&mapping){
        if(n == 0 )
        return mapping[n];
        
        int val = 0;
        int posMultiplyFactor = 1;
        
        while(n){
            int last = n%10;
            val = (mapping[last]*posMultiplyFactor) + val;
            posMultiplyFactor *=10;
            n/=10;
        }
        
        return val;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        multimap<int,int>m;
        
        for(auto &num:nums){
            int formed = getMapped(num,mapping);
            m.insert({formed,num});
        }
        
        nums.clear();
        
        for(auto &it:m){
            nums.push_back(it.second);
        }
        
        return nums;
        
    }
};