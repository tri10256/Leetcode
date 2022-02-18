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
        int grlastpos = 0;
        int grinitial = 0;
        for(i = 0;i<n;i++){
            grlastpos = max(grlastpos,last[s[i]-'a']);
            
            if(i == grlastpos){
                ans.push_back(grlastpos-grinitial+1);
                grinitial= i+1;
            }
        }
        
        return ans;
    }
};