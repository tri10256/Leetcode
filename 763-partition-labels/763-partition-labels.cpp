class Solution {
public:
    vector<int> partitionLabels(string s) {
        int freq[26] = {};
        int n = s.size();
        
        for(auto ch:s){
            freq[ch-'a']++;
        }
        
        int i = 0;
        int j = 0;
        vector<int>ans;
        string group = "";
        unordered_map<char,int>gr;
        while(j<n){
             char ch = s[j];
          
            bool flag = false;
            for(auto &it:gr){
                if(it.second>0){
                    flag = true;
                }
            }
            if(flag){
                
            if(!gr.count(ch)){
              group+=ch;
              gr[ch] = freq[ch-'a'];
              freq[ch-'a']--;
              gr[ch]--;
            }else{
                 group+=ch;
                 gr[ch]--;
                 freq[ch-'a']--;
             }
                
            }else{
              if(group.size()>0)
              ans.push_back(group.size());
                
              group.clear();
              gr.clear();
                
              group+=ch;
              gr[ch] = freq[ch-'a'];
              freq[ch-'a']--;
              gr[ch]--;
            }
          j++;
        }
        ans.push_back(group.size());
        
        return ans;
        
    }
};