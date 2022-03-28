class Solution {
public:
   
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto num:nums)
            st.insert(num);
        int ans = 0;
        
        for(auto num:st){
            if(!st.count(num-1)){
                int curr = 1;
                
                while(st.count(num+1)){
                    curr++;
                    num++;
                }
                
                ans = max(ans,curr);
            }
        }
        
       
        
        return ans;
        
    }
};