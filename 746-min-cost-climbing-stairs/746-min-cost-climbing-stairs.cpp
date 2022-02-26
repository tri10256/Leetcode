class Solution {
public:
    
    int cache[1005];
    
    int mincost(vector<int>&cost,int n,int i){
         
        for(int j = n-1;j>=i;j--){
        
        int ans1 = cost[j] + cache[j+1];
        int ans2 = cost[j] + cache[j+2];
            
        cache[j]= min(ans1,ans2);
            
        }
        
        
        return cache[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int   n = cost.size();
        memset(cache,0,sizeof(cache));
     
        int ans1= mincost(cost,n,0);
        int ans2 = mincost(cost,n,1);
        
        return min(ans1,ans2);
    }
};