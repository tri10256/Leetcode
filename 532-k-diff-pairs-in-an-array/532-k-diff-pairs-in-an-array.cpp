class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int>freq;
        for(auto &num:nums){
            freq[num]++;
        }
        

       int count = 0;
        for(auto &num:freq ){
            if(freq.count(num.first+k) && k!=0){
               count++;
            }else if(k==0){
               if(freq[num.first]>1){
                  count++;
               }
            }
        }
       
       return count;
    }
};