class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
       
        
        int sum =0;
           
        unordered_map<int,int>map;
        map[0] = -1;
        int len = 0;
        
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(!map.count(sum)){
                map[sum]=i;
            }else if(map.count(sum)){
                
                int temp_len = i-map[sum];
                len=max(temp_len,len);
            }  
        }
        
        
        return len;
    }
};