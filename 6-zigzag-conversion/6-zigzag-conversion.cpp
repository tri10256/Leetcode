class Solution {
public:
    string convert(string s, int n) {
      int sz = s.size();
      if(n == 1) return s;
        
        vector<string>rows(min(sz,n));
        int curRow = 0;
        bool godown = false;
        
        for(char c:s){
            rows[curRow]+=c;
            if(curRow == 0 || curRow == n-1){
                godown = !godown;
            }
            
          if(godown)
              curRow++;
          else
              curRow--;
          //curRow+=godown?1:-1;
        }
        
        string ret;
        for(string str:rows){
            ret+=str;
        }
        
        return ret;
    }
};