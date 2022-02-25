class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        
        stack<string>st;
            
        string word = "";
        while(str>>word){
            st.push(word);
        }
        string ans = "";
        while(!st.empty()){
            string temp = st.top();
            st.pop();
            ans+=temp;
            ans+=" ";
        }
        ans.pop_back();
        
        return ans;
    }
};