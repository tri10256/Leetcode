class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int,int>>q;
        q.push({click[0],click[1]});
        
         int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
         // int dirx[] = {-1,-1,-1,0,0,1,1,1};
         // int diry[] = {-1,0,1,1,1,0,-1,-1};
        
        while(!q.empty()){
            
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          
         if(board[x][y] == 'M'){
             board[x][y] ='X';
             return board;
         }
       
         int count = 0;
          for(int i = 0;i<8;i++){
              int nx = x+dir[i][0];
              int ny = y+dir[i][1];
              
              if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]=='M'){
              count++;
            }
          }
          
             if(count == 0 && board[x][y] =='E' ){
             board[x][y] = 'B';
             for(int i = 0;i<8;i++){
              int nox = x+dir[i][0];
              int noy = y+dir[i][1];
              
              if(nox>=0 && noy>=0 && nox<m && noy<n && board[nox][noy]=='E'){
                   q.push({nox,noy});
                }   
              }  
             }
            else if(count>0 && board[x][y] == 'E'){
                 board[x][y] = (count+'0');
             }
          
        }
        
        return board;
    }
};