class Solution {
public:
    
    // if(nums[i] != nums[i-1] && nums[i] != nums[i+1] && (nums[i] > nums[i-1] && nums[i] > nums[i+1]) || (nums[i]<nums[i-1] && nums[i] < nums[i+1]))
    //             count++;
    //     }
    int countHillValley(vector<int>& nums) {
        int count = 0;
        for(int i = 1;i<nums.size() -1;i++){
            while(nums[i] == nums[i+1])
                i++;
            int left = -2;
            bool flagleftbig = false;
            bool flagleftsmall  = false;
            for(int j = i-1;j>= 0;j--){
                if(nums[j] > nums[i]){
                    left = nums[j];
                    flagleftbig = true;
                    //cout<<"big"<<nums[j]<<endl;
                    break;
                }else if(nums[j] < nums[i]){
                    left = nums[j];
                    flagleftsmall = true;
                   // cout<<"small"<<nums[j]<<endl;
                    break;
                }
            }
            
            int right = -2;
            bool flagrightbig = false;
            bool flagrightsmall  = false;
            
             for(int j = i+1;j< nums.size();j++){
                if(nums[j] > nums[i]){
                    right = nums[j];
                    flagrightbig = true;
                   /// cout<<"rightbig"<<nums[j]<<endl;
                    break;
                }else if(nums[j] < nums[i]){
                    left = nums[j];
                    flagrightsmall = true;
                  ///  cout<<"rightsmall"<<nums[j]<<endl;
                    break;
                }
            }
            
           if(flagleftbig && flagrightbig){
              // cout<<"bada"<<endl;
               count++;
           }else if(flagleftsmall && flagrightsmall){
               //cout<<"chota"<<endl;
               count++;
           }
            
        }
        return count;
    }
};