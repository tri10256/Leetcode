class Solution {
public:
    int dp[500][500];
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        int maxlen = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               
                if(matrix[i-1][j-1] == '1'){
                    
                   
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1; 
                    
                   maxlen = max(maxlen,dp[i][j]);
                    
                 }
            }
        }
        
        
        return maxlen*maxlen;
        
    }
};