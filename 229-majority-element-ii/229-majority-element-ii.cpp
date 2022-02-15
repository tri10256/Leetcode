class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        
        int prev1 = INT_MIN;
        int prev2  = INT_MIN;
        int poll1 = 0;
        int poll2 = 0;
        
        int n  = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i]== prev1){
                poll1++;
            }else if( nums[i] == prev2){
                poll2++;
            }else if(poll1<=0){
                prev1 = nums[i];
                poll1++;
            }else if(poll2<=0){
                prev2 = nums[i];
                poll2++;
            }else{
                poll1--;
                poll2--;
            }
        }
        
        cout<<prev1<<" "<<prev2<<endl;
        
        poll1 = 0;
        poll2 = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == prev1)
                poll1++;
            else if(nums[i] == prev2){
                poll2++;
            }
        }
        
        if(poll1>n/3)
            ans.push_back(prev1);
        if(poll2>n/3)
            ans.push_back(prev2);
        
        return  ans;
    }
};