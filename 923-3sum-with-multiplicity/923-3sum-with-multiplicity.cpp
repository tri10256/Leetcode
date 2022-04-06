class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long  count = 0;
        sort(arr.begin(),arr.end());
        
        for(int i = 0;i<n;i++){
           
                int find = target - arr[i];
                int k = n -1;
                int j = i+1;
               
            
                while(j < k){
                    if(arr[j]+arr[k] < find){
                        j++;
                    }else if(arr[j]+arr[k] > find){
                        k--;
                    }else if(arr[j] != arr[k]){
                       int left = 1, right = 1;
                        
                        while( j+1 < k && arr[j] == arr[j+1]){
                            left++;
                            j++;
                        }
                        
                        while( k -1 > j && arr[k] == arr[k-1]){
                            right++;
                            k--;
                        }
                        
                        count+= left*right;
                        count%=mod;
                        j++;
                        k--;
                    }else{
                        count+=(k-j+1)*(k-j)/2;
                        count%=mod;
                        break;
                    }
               
            }
            
        }
                       
        return count;
    }
};