class Solution {
public:
    
    vector<vector<int>>dp;
    int recur(int n,int i,int prev){
        if(i == n)
            return 0;
        int ch1 = INT_MAX, ch2 = INT_MAX;
        if(dp[i][prev] != -1)
            return dp[i][prev];
        
        if(2*i<=n){
            int ans = recur(n,2*i,i);
            if(ans == INT_MAX)
                ch1 = INT_MAX;
            else
                ch1 = 2 + ans;
        }
        if(prev != 0 && i+prev <= n){
            int ans = recur(n,i+prev,prev);
            if(ans == INT_MAX)
                ch2 = INT_MAX;
            else
                ch2 = ans + 1;
        }
        
        return dp[i][prev] = min(ch1,ch2);
    }
    int minSteps(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return recur(n,1,0);
    }
};