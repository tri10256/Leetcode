class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
       
        // int lowest = *min_element(nums.begin(),nums.end());
        // int highest = *max_element(nums.begin(),nums.end());
        int lowest = nums[0];
        int highest = nums.back();
        vector<bool>st(highest+1,0);
        long long int val = 0;
        
        for(auto num:nums)
            st[num] = 1;
        
          long long int a = 1;
          long long int an = lowest-1;
          int n = an-a+1;
          if(n<=k){
          long long int sum = 2*a + (n-1);
            sum*=(n);
            sum/=2;
            val+=sum;
            k -= n;
         }
       else{
          long long int sum = 2*a + (k-1);
            sum*=(k);
            sum/=2;
            val+=sum;
            k = 0;
         }
            
        for(int i = lowest;i<highest && k>0;++i){
            if(!st[i]){
                val+=i;
                st[i] = 1;
                --k;
            }
        }
        
        if(k>0){
        unsigned long long int j= highest+1;
        unsigned long long int sum = 2*j + (k-1);
            sum*=k;
        sum/=2;
        val+=sum;
        }
    
        return val;
        
    }
};