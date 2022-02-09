class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto &num:nums){
            freq[num]++;
        }
        

       int count = 0;
        for(auto &num:nums ){
            if(freq.count(num+k) && k!=0){
               count+=freq[num+k];
             }
        }
       
       return count;
    }
};