class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1 = nums[0];
        for(int i = 1;i<nums.size();i++){
            xor1 = xor1^nums[i];
        }
        
        int sb = 0;
        ////rightmostsetbit
        if(xor1!=INT_MIN)
        sb = xor1&~(xor1-1);
        else{
            sb = xor1&~(xor1);
        }
        
        int res1 = 0;
        int res2 = 0;
        
        for(int i = 0;i<nums.size();i++){
            if((nums[i]&sb)!=0){
                res1 = res1^nums[i];
            }
            else{
                res2 = res2^nums[i];
            }
        }
        
        return {res1,res2};
    }
};