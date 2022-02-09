class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int>freq;
        for(auto &num:nums){
            freq[num]++;
        }
        
        set<pair<int,int>>st;
       
        for(auto &num:nums ){
            if(freq.count(num+k) && k!=0){
                st.insert({num,num+k});
            }else if(k==0){
               if(freq[num]>1){
                   st.insert({num,num});
               }
            }
        }
       
        return st.size();
    }
};