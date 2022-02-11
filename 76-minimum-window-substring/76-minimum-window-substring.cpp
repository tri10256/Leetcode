class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size()==0 || t.size()==0){
            return "";
        }
        
        unordered_map<char,int>freq;
        
        for(int i = 0;i<t.size();i++){
            freq[t[i]]++;
        }
        
        int req = freq.size();
        
        int l = 0;
        int r = 0;
        
        int formed = 0;
        
        unordered_map<char,int>windowCount;
        
        int ans[] = {-1,0,0};
        
        while(r<s.size()){
            
            char c = s[r];
            
            windowCount[c]++;
            
            if(freq.count(c) && windowCount[c]==freq[c]){
                formed++;
            }
            
            while(l<=r && formed == req){
              
                 c = s[l];
                
                if(ans[0]==-1 || r-l+1<ans[0]){
                    ans[0] = r-l+1;
                    ans[1] = l;
                    ans[2] = r;    
                }
                
            
            windowCount[c]--;
                
            if(freq.count(c) && windowCount[c]<freq[c]){
                formed--;
            }
            
          l++;  
        }
        r++;
      }            //////s.substring in java give (s.substring(start,end))
        
                  ///// while s.substr in c++ gives s.substr(start,len)
                 ////// so here length will be ans[2]-ans[1]+1;
        
        return ans[0]==-1?"":s.substr(ans[1],ans[0]);
    }
};