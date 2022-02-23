class Solution {
public:
    
    unordered_set<string>st;
    unordered_map<string,bool>dp;
    
    bool helper(string s){
        int len = s.size();
        if(len == 0)
            return true;
        
        if(dp.count(s))
            return dp[s];
        
        for(int i = 1 ;i<=len;i++){
            if(st.count(s.substr(0,i)) && helper(s.substr(i,len-i))){
                return dp[s] = true;
            }
        }
        
        return dp[s] =  false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(auto &s:wordDict){
            st.insert(s);
        }
        
        return helper(s);
    }
};