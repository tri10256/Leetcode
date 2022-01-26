class Solution {
public:
    
    unordered_map<int,int>cache;
    
    int recur(vector<int>&freq,int i){
        
         if(i>=freq.size())
             return 0;
        if(cache.count(i))
            return cache[i];
         
        int ans1 = recur(freq,i+1);
        int ans2 = i*freq[i] + recur(freq,i+2);
        
        if(!cache.count(i))
            cache[i] = max(ans1,ans2);
        
        return cache[i];
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>freq(10004,0);
        
        for(int i = 0;i<n;i++){
            freq[nums[i]]++;
        }
        
        return recur(freq,0);
    }
};