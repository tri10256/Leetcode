class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size()<3)
            return 0;
        
        /*
         pattern problem,
         1,2,3 = 0 + 1 = 1
         1,2,3,4 = 1 +2 = 3
         1,2,3,4,5 = 3 + 3 = 6
         1,2,3,4,5 = 6 + 4 = 10
        
        */
        
        int cdiff = nums[1] - nums[0];
        int cnt = 0;
        int totalcnt = 0;
        int k = 1;
        
        for(int i = 2;i<nums.size();i++){
            int diff = nums[i] - nums[i-1];
            if(diff == cdiff){
                cnt+=k;
                k++;
            }else{
                totalcnt+=cnt;
                cdiff = diff;
                k = 1;
                cnt = 0;
            }
        }
        
        totalcnt+=cnt;
        
        return totalcnt;
    }
};