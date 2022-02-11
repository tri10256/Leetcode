class Solution {
public:
    bool checkInclusion(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(n==0 || m==0)
            return false;
        
        unordered_map<char,int>freq;
        
        for(auto &ch:s){
            freq[ch]++;
        }
        
        int req = freq.size();
        
        int l = 0;
        int r = 0;
        int ans[] = {-1,0,0};
        unordered_map<char,int>windowcount;
        int formed = 0;
        
        while(r<m){
            
            char ch = t[r];
            windowcount[ch]++;
            
            if(freq.count(ch) && freq[ch] == windowcount[ch]){
                formed++;
            }
            
            while(l<=r && formed == req){
                
                if(ans[0]==-1 || r-l+1<ans[0]){
                    ans[0] = r-l+1;
                    ans[1] = l;
                    ans[2] = r;
                }
                
                char c = t[l];
                windowcount[c]--;
                
                if(freq.count(c) && windowcount[c]<freq[c]){
                    formed--;
                }
                
              l++;
            }
            r++;
        }
        
        if(ans[0]==-1)
            return false;
        if(ans[0] != n)
            return false;
        
        return true;
    }
};