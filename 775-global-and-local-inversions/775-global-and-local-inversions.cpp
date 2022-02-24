class Solution {
public:
    
    long long int merge(vector<int>&arr,vector<int>&temp,int left,int mid,int right){
        
        int i,j,k;
        long long int inversions = 0;
        
        i = left;
        j = mid;
        k = left;
        
        while(i<=mid-1 && j<=right){
            if(arr[i]<=arr[j]){
                temp[k] = arr[i];
                i++;
                k++;
            }else{
                temp[k] = arr[j];
                j++;
                k++;
                
                inversions+=(mid - i);
            }
        }
        
        while(i<=mid-1){
            temp[k] = arr[i];
            i++;
            k++;
        }
        
        while(j<=right){
            temp[k] = arr[j];
            j++;
            k++;
        }
        
        for(int s = left;s<=right;s++){
            arr[s] = temp[s];
        }
        
        return inversions;
    }
    long long int mergesort(vector<int>&nums,vector<int>&temp,int left,int right){
        
        long long int inversions  = 0;
        if(right>left){
            
            int mid = (right +left)/2;
            
            inversions+=mergesort(nums,temp,left,mid);
            inversions+=mergesort(nums,temp,mid+1,right);
            inversions+=merge(nums,temp,left,mid+1,right);
            
        }
        
        return inversions;
    }
    
    long long int global(vector<int>&nums){
        
        int n = nums.size();
        vector<int>temp(n);
        
        return mergesort(nums,temp,0,n-1);
    }

    bool isIdealPermutation(vector<int>& nums) {
        
        vector<int>nums2  = nums;
        
        long long int l = 0;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])
                l++;
        }
        
       long long int g = global(nums);
       
       
        return (g==l);
    }
};