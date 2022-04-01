class Solution {
public:
    void ans(vector<char>&s,int i,string &str)
    {
        if(i==s.size())
            return;
        ans(s,i+1,str);
        str.push_back(s[i]);
    }
    void reverseString(vector<char>& s) {
      /*  stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            st.push(s[i]);
        }
        int i=0;
        while(!st.empty())
        {
            s[i]=st.top();
            st.pop();
            i++;
            
        }*/
        // reverse(s.begin(),s.end());
        int i=0;
        int j=s.size()-1;
        while(i<j)
            swap(s[i++],s[j--]);
        
        // string str="";
        // ans(s,0,str);
        // for(int i=0;i<s.size();i++)
        //     s[i]=str[i];
    }
   
    
};