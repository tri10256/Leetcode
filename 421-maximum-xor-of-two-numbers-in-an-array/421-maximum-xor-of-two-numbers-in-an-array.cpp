class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxresult = 0;
        int mask = 0;
        
        for(int i = 31;i>=0;i--){
            
            mask = mask | (1<<i);
            unordered_set<int>st;
            
            for(auto num:nums){
                int leftpart = num & mask;
                st.insert(leftpart);
            }
            
            int reqmax = maxresult | (1<<i);
            
            for(auto leftpart:st){
                
                int b = reqmax ^ leftpart;
                if(st.count(b)){
                    maxresult = reqmax;
                    break;
                }
                
            }
            
        }
        
        return maxresult;
    }
};