class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int len = arr.size();
        int maxi = 0;
        int i = 1;
        
        if(len < 3)
            return 0;
        
        
        while(i<len-1){
            
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                
                int low = i-1;
                int high = i+1;
                
                while(low >= 0 && arr[low] < arr[low+1])
                    low--;
                
                while(high < len && arr[high-1] > arr[high])
                    high++;
                
                maxi = max(maxi,high - low - 1);
                
                i = high;
                
            }else{
                i++;
            }
        }
        
        return maxi;
    }
};