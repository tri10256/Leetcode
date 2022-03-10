class Solution {
public:
    vector<int>dp;
    
    int Profit(vector<int>&prices,int curr,int n){
        if(curr>=n)
            return 0;
        if(dp[curr] != -1)
            return dp[curr];
        
        int maxVal  = 0;
        
        for(int i = curr+1;i<n;++i){
            if(prices[curr] < prices[i])
                maxVal = max(maxVal,prices[i] - prices[curr] + Profit(prices,i+2,n));
        }
        
        maxVal = max(maxVal,Profit(prices,curr+1,n));
        dp[curr] = maxVal;
        
        return dp[curr];
    }
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        dp.resize(n,-1);
        
        return Profit(prices,0,n);
    }
};