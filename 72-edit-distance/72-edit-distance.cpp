class Solution {
public:
     
    vector<vector<int>>dp;
    int lcs(string &word1, string &word2,int n, int m){
       if(n==0) return dp[n][m]= m;
       if(m==0) return dp[n][m]=n;
        
        if(dp[n][m]!=INT_MAX)
            return dp[n][m];
        
        if(word1[n-1] == word2[m-1]){
           return dp[n][m] = lcs(word1,word2,n-1,m-1);
        }
            
        
            int c1 = lcs(word1,word2,n,m-1); //insert
            int c2 = lcs(word1,word2,n-1,m); //delete
            int c3 = lcs(word1,word2,n-1,m-1); //replace
            
          return dp[n][m] =  1+ min({c1,c2,c3});
     }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        dp.resize(n+1,vector<int>(m+1,INT_MAX));
      
        int len = lcs(word1,word2,n,m);  
        
        return len;
    }
};