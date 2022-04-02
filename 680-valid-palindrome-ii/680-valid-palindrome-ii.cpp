class Solution {
public:
    bool palcheck(string str)
    {
        int s=0;
        int e=str.size()-1;
        while(s<=e)
        {
            if(str[s++]!=str[e--])
                return false;
        }
        return true;
    }
    bool validPalindrome(string str) {
        int s=0;
        int e=str.size()-1;
        while(s<=e)
        {
            if(str[s]!=str[e])
            {
                return palcheck(str.substr(s,e-s))||palcheck(str.substr(s+1,e-s));
            }
            else
            s++;
            e--;
        }
        return true;
        
    }
};