class Solution {
public:
    vector<vector<int>> dp;
    bool match(string &s, string &p, int i, int j) {
        
        if(j == p.length())
            return i == s.length();
        
        if(i > s.length())
            return false;
        
        bool ans = false;
        
        if(dp[i][j] != -1)
           return dp[i][j];
        
        if(p[j] == '*')
            ans = match(s, p , i , j+1) || match(s, p , i+1, j);
        else
            ans = i < s.length() && (p[j] == '?' || p[j] == s[i]) && match(s, p, i+1, j+1);
        
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        dp.assign(s.length()+1, vector<int>(p.length()+1, -1));
        return match(s, p, 0, 0);
    }
};