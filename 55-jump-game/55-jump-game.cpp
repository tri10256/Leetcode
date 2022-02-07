class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        
        /*1,2,3,5
        0->0+nums[0] = 1;
        reachable = 1;
        1->1+nums[1]= 1+2 = 3;
        reachable = max(reachable,1+nums[i]);
        i>reachable;
        return false;
    
        */
        for(int i = 0;i<nums.size();i++){
            
            if(i>reachable)
                return false;
            reachable = max(reachable,i+nums[i]);
        }
        
        return true;
    }
};