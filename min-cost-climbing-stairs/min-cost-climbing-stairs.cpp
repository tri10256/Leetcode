class Solution {
public:
    
    unordered_map<int,int>cache;
    
    int mincost(vector<int>&cost,int n,int i){
        if(i>=n)
            return 0;
        if(cache.count(i))
            return cache[i];
        
        int ans1 = cost[i] + mincost(cost,n,i+1);
        int ans2 = cost[i] + mincost(cost,n,i+2);
        
        if(!cache.count(i))
            cache[i] = min(ans1,ans2);
        
        return cache[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int   n = cost.size();
     
        int ans1= mincost(cost,n,0);
        int ans2 = mincost(cost,n,1);
        
        return min(ans1,ans2);
    }
};