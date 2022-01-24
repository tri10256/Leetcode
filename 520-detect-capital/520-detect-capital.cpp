class Solution {
public:
    bool detectCapitalUse(string word) {
        int n =  0;
        for(int i =0;i<word.size();i++){
            if(isupper(word[i]))
               n++;
        }
        if(n==word.size())
            return true;
        if(n==1 && isupper(word[0]))
            return true;
        if(n==0)
            return true;
        
        return false;
    }
};