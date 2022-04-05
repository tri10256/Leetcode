class Solution {
public:
    bool isPerfectSquare(int num) {
        /*
          1 = 1
          1+3 = 4
          1+3+5 = 9
          1+3+5+7 = 16
          1+3+5+7+9 = 25
          1+3+5+7+9+11 = 36
        */
        
        int i  = 1;
        while(num > 0){
            num-=i;
            if(!num)
                return true;
            i+=2;
        }
        
        return false;
        
    }
};