class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n0 = 0;
        int n1 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                n0++;
                nums[i]=-1;
            }else{
                n1++;
            }
        }
        if(n0 == n1)
            return 2*n0;
        
        int sum =0;
            // sum->i  sum->j ( leng - j-i )
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