class Solution {
public:
    
    
   
    
    
    
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int n= board.size();
        int m = board[0].size();
        int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int count = 0;
                for(int k = 0 ;k<8;k++){
                    int nx = i+dir[k][0];
                    int ny = j+dir[k][1];
                    
                    if(nx>=0 && ny>=0 && nx<n && ny<m){
                       if(board[nx][ny]==1){
                        count++;
                      }
                   }
                }
                
        ///if 1 ->0 (numbers of count less than 2 in all directions)
        // if(1->0) (if count of all directions is greater than 3)
        // (1->1) , (if count of all direction is 2 or 3)
        // 0->1     (if count of all directions is 3)
                
                if(board[i][j]==1 && count<2){
                    ans[i][j] = 0;
                }else if(board[i][j] == 0 && count == 3){
                    ans[i][j] = 1;
                }else if(board[i][j]==1 && count >3){
                    ans[i][j] = 0;
                }
                else if(board[i][j]==1 && (count==2 || count==3)){
                    ans[i][j] = 1;
                }
                
            }
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                board[i][j] = ans[i][j];
            }
        }
      
    }
};