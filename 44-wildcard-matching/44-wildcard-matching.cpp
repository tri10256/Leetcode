class Solution {
public:
    unordered_map<string,bool>dp;
    bool match(string &s, string &p, int i, int j) {
        
        if(j == p.length())
            return i == s.length();
        
        if(i > s.length())
            return false;
        
         string key = to_string(i) + "*" + to_string(j);
        
        if(dp.count(key))
           return dp[key];
        
        bool ans = false;
        
       
        
        if(p[j] == '*')
            ans = match(s, p , i , j+1) || match(s, p , i+1, j);
        else
            ans = (p[j] == '?' || p[j] == s[i]) && match(s, p, i+1, j+1);
        
        return dp[key] = ans;
    }
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }
};