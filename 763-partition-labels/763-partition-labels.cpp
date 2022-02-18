class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {};
        int n = s.size();
         
        for(int i = 0; i<n;i++){
            last[s[i]-'a'] = i;
        }
         
        int i = 0;
        vector<int>ans;
        int lastpos = 0;
        int initial = 0;
        for(i = 0;i<n;i++){
            lastpos = max(lastpos,last[s[i]-'a']);
            
            if(i == lastpos){
                ans.push_back(i-initial+1);
                initial= i+1;
            }
        }
        
        return ans;
    }
};