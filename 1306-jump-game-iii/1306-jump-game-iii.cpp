class Solution {
public:
    
    bool dfs(vector<int>&arr,int i,int n,vector<bool>&vis){
        if(i<0 || i>=n || vis[i] !=0)
            return false;
        if(arr[i] == 0)
            return true;
         vis[i] = 1;
        
        bool ans1 = dfs(arr,i-arr[i],n,vis);
        bool ans2 = dfs(arr,i+arr[i],n,vis);
        
        return (ans1|| ans2);
    }
    
    bool canReach(vector<int>& arr, int start) {
     
        int n = arr.size();
        vector<bool>vis(n,0);
        return dfs(arr,start,n,vis);
    }
};