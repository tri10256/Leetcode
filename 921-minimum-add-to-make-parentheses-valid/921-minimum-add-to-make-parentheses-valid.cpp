class Solution {
public:
    int minAddToMakeValid(string s) {
         stack<char>st;
        
        int count = 0;
        for(int i = 0;i<s.size();){
            if(s[i]=='('){
                st.push(s[i]);
                i++;
            }else if(s[i] == ')'){
                while(!st.empty() && s[i]== ')'){
                    st.pop();
                    i++;
                }if(s[i] == ')'){
                    i++;
                    count++;
                }
            }
        }
        if(st.size()>0){
            count+=st.size();
        }
        
        return count;
    }
};