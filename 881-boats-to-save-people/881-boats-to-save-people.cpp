class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        int count = 0;
        int i = 0;
        int j = n-1;
        
        while(i<=j){
            if((arr[i] + arr[j]) <= limit ){
                count++;
                i++;
                j--;
            }else{
                count++;
                j--;
            }
        }
        
        return count;
    }
};