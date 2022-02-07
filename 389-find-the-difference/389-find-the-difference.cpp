class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<char,int>freq;
        for(auto ch:t){
            freq[ch]++;
        }
        for(auto ch:s){
            freq[ch]--;
        }
        for(auto it:freq){
          if(it.second>0)
              return it.first;
        }
        
        return '*';
    }
};