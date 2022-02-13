class Solution {
public:
    bool isHappy(int n) {
       unordered_set<int>st;
       
        while(n!=1 && !st.count(n) ){
            
            st.insert(n);
            int temp = n;
            int sum = 0;
            
            while(temp!=0){
                int digit = temp%10;
                sum+=digit*digit;
                temp/=10;
            }
            
            n=sum;   
        }
        
        if(st.count(n))
            return false;
        
       return true;
    }
};