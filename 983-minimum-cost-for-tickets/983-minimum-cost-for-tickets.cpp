class Solution {
public:
    vector<vector<int>>dp;
    int recur(vector<int>&days,vector<int>&costs,int i ,int validity){
        if(i >= days.size())
            return 0;
        
        if(dp[i][validity] != -1)
            return dp[i][validity];
        
        int ans = 0;
        if(days[i] <= validity){
            ans = recur(days,costs,i+1,validity);
        }else{
            int ans1 = costs[0] + recur(days,costs,i+1,days[i]); //jis din kharida hai us 
            //din se lekar 
            int ans2 = costs[1] + recur(days,costs,i+1,days[i]+6);
            int ans3 = costs[2] + recur(days,costs,i+1,days[i]+29);
            
            ans = min({ans1,ans2,ans3});
        }
        
        return dp[i][validity] = ans;    
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int maxi = days[n-1] + 30;
        dp.resize(n,vector<int>(maxi,-1));
        
        return recur(days,costs,0,0);
    }
};