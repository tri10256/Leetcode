class Solution {
public:
  

    set<vector<int>>st;
    int generate(vector<int>&nums,int k, int p){
        
        int n = nums.size();
        for(int i = 0;i<n;i++){
               vector<int>vec;
               int cnt = 0;
            for(int j = i;j<n;j++){
               vec.push_back(nums[j]);
               if(nums[j]%p == 0)
                cnt++;
                   
                if(cnt > k)
                break;
                
                st.insert(vec);
                   
                }
        }
        
        
       return st.size();
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        
        return generate(nums,k,p);
    
    }
};