class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans = "";
        
        for(int i = 0;i<n;++i){
            if(k-n+i >=26){
                ans+='z';
                k-=26;
            }else{
                ans+=((k-n+i)+'a' );
                k-=(k-n+i +1);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};