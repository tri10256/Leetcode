/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        
        int l = 1;
        int h = n;
        int num = 0;
        
        while(l<=h){
            int mid = l+(h-l)/2;
            
            int status = guess(mid);
            
           if(!status){
               return mid;
           }else if(status == -1){
               h = mid;
           }else if(status){
               l = mid+1;
           }
        }
        
        return num;
    }
};