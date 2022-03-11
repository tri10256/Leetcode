class Solution {
public:
    string smallestSubsequence(string s) {
        int count[26]={0};//stores the frequency of characters
        int visited[26]={0};//visited characters
        int n=s.length();
        
        //stores count of each character
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        string res="";//stores the resultant string
        for(int i=0;i<n;i++){
            //decrease the count of current character
            count[s[i]-'a']--;
            //if character is not already in answer
            if(!visited[s[i]-'a']){
                //last chracter>s[i] and its count >0
                while(res.length()>0 && res.back()>s[i] && count[res.back()-'a']>0){
                    //mark letter unvisited
                    visited[res.back()-'a']=0;
                    res.pop_back();
                }
                //add s[i] in res and mark it visited
                res+=s[i];
                visited[s[i]-'a']=1;
            }
        }
        return res;
    }
};