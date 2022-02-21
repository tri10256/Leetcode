class Solution {
public:
    int minAddToMakeValid(string s) {
        ///submitted once with the use of one stack and one string 
        ///Time O(n), space O(n);
        
        //sol O(n) O(1) "kiski jarurat pad rahi hai usko dekho"
        
        int left = 0;
        int right = 0;
        for(auto ch:s){
            if(ch == '('){
                right++;
            }else if(right>0){
                right--;
            }else{
                left++;
            }
        }
        
        return left+right;
    }
};