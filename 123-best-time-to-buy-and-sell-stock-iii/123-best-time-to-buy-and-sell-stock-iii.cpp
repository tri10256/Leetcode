class Solution {
public:
    vector<vector<vector<int>>>dp;
    
    int recur(vector<int>&prices,int pos,int t,bool bought,int n){
        
        if(pos>=n || t == 0){
            return 0;
        }
        
        if(dp[bought][t][pos]!=-1)
            return dp[bought][t][pos];
        
        int result = recur(prices,pos+1,t,bought,n);
        
        if(bought)
            result = max(result, recur(prices,pos+1,t-1,false,n) + prices[pos]);
        else
            result = max(result,recur(prices,pos+1,t,true,n) - prices[pos]);
        
        return dp[bought][t][pos] = result;
    }
    
  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        dp.resize(2,vector<vector<int>>(3,vector<int>(n,-1)));
        return recur(prices,0,2,false,n);
    }
};