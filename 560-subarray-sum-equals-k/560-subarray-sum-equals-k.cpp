class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum  = 0;
        int n = nums.size();
        unordered_map<int,int>map;
        /*
        sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1. Can we use this property to optimize it.
        
        subarray sum = sum(i,j) that is given = k;
        sum(0,j) = we are calculating by moving in array;
        we don't know sum (0,i)= x;
        
        equations
        sum(i,j) = sum(0,j) - x;
        x = sum(0,j) - sum(i,j);
        x = sum(0,j) - k;
        */
        
        map[0] = 1;
        for(int j = 0;j<n;j++){
            sum+=nums[j];
            if(map.count(sum-k)){
                count+=map[sum-k];
            }
            
            map[sum]++;
        }
        
        return count;
    }
};