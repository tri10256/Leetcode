class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       
        int count = 0;
        int sum  = 0;
        unordered_map<int,int>freq;
        freq[0] = 1;
        
        for(auto x:nums){
            sum+=x;
            
           int rem = sum%k;
            if(rem<0)
                rem+=k;
            count+=freq[rem];
            freq[rem]++;
        }
        
      
        
        return count;
    }
};