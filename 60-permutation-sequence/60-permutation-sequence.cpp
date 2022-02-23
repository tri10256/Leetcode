class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ///step1=traverse from back find a number smaller than prev;
        ///step2 = traverse from back and find a number greater than number find         ////in stpe1;
        ///if then swap the both numbers and reverse as from the step1+1 index to  /////////last to find the lexicographically smaller
        //// 
        
        int n = nums.size(),k,l;
        
        for(k= n-2;k>=0;k--){
            
            if(nums[k]<nums[k+1])
                break;
        }
        
        if(k<0){
            reverse(nums.begin(),nums.end());
        }else{
            
            for(l = n-1;l>=0;l--){
                if(nums[l]>nums[k]){
                    break;
                }
            }
            swap(nums[l],nums[k]);
            reverse(nums.begin()+k+1,nums.end());
        }
        
    }
    string getPermutation(int n, int k) {
        vector<int>vec;
        for(int i = 1;i<=n;i++){
             vec.push_back(i);
        }
        while(k>1){
            nextPermutation(vec);
            k--;
        }
        string s = "";
        for(auto &i:vec){
            s+=(i+'0');
        }
        
        return s;
    }
};