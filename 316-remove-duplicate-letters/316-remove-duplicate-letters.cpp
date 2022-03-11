class Solution {
public:
    string removeDuplicateLetters(string s) {
         int freq[26] = {0};
       int n = s.length();
       unordered_set<char> Set;
       for(int i = 0; i < n; ++i) {
            freq[s[i]-'a']++;
        }
        
        stack<char> st;
        for(int i = 0; i < n; ++i) {
            freq[s[i]-'a']--;
            if(Set.count(s[i]))
                continue;
            
            while(!st.empty() && st.top() > s[i] && freq[st.top()-'a'] > 0) {
                Set.erase(st.top());
                st.pop();
            }
    
            st.push(s[i]);
            Set.insert(s[i]);
        }
        
        string str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};