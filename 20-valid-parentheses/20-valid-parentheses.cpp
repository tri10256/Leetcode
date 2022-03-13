class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(auto &c:s){
            
            if(c =='(' or c == '{' or c == '['){
                st.push(c);
            }else{
                if(c == ')' or c == '}' or c == ']'){
                    if(st.empty()){
                        cout<<"e";
                        return false;
                    }
                    
                    char s = st.top(); 
                    st.pop();
                    if(!((s =='(' && c ==')') or (s =='{' && c =='}') or (s =='[' && c ==']')))
                        return false;    
                }
            }
        }
        if(!st.empty())
            return false;
        
        return true;
    }
};