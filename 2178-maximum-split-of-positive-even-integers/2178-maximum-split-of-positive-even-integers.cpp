class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long>nums;
        long long int numsum = 0;
        for(int i = 2;numsum<=finalSum;i+=2){
            nums.push_back(i);
            numsum+=i;
        }
        int j = 0;
        int n = nums.size();
        unordered_set<long long>st;
        vector<long long>ans;
        long long int sum = 0;
        
        while(j<n){
              sum+=nums[j];
             st.insert(nums[j]);
             
             if(sum>=finalSum){
                 
                 while(sum>finalSum){
                     long long int val = sum-finalSum;
                     if(st.count(val)){
                         sum-=val;
                         st.erase(val);
                     }else{
                         return {};
                     }
                 }
                 if(sum==finalSum){
                     for(auto it:st){
                         ans.push_back(it);
                     }
                     return ans;
                 }
             }
            
            j++;
        }
        
        if(ans.size()==0)
            return {};
        return ans;
    }
};