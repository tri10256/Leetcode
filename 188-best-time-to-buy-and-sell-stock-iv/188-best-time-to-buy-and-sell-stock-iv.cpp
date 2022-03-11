class Solution {
public:
    vector<vector<vector<int>>>dp;
    int recur(vector<int>&prices,int pos,int k, bool bought){
        if(pos>=prices.size() || k == 0)
            return 0;
        
        if(dp[bought][k][pos] != -1)
            return dp[bought][k][pos];
        
        int result = recur(prices,pos+1,k,bought);
        
        if(bought){
            result = max(result,recur(prices,pos+1,k-1,false) + prices[pos]);
        }else{
            result = max(result,recur(prices,pos+1,k,true) - prices[pos]);
        }
        
       
        return dp[bought][k][pos] = result;
    }
    
   
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(2,vector<vector<int>>(k+1,vector<int>(n,-1)));
        
        return recur(prices,0,k,0);
    }
};